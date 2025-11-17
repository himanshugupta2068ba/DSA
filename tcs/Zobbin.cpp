#include <bits/stdc++.h>
using namespace std;

// Graph representation
map<int, set<int>> adj1, adj2;
set<int> V;
map<int, int> deg1, deg2;
map<int, int> target_P;
set<vector<int>> simple_cycles;

// --- Graph Isomorphism Finder ---
bool find_isomorphism(const vector<int>& nodes1, const vector<int>& nodes2,
                      map<int, int>& current_P, set<int>& used_v, int node_index) {
    if (node_index == (int)nodes1.size()) {
        target_P = current_P;
        return true;
    }

    int u = nodes1[node_index];
    for (size_t i = 0; i < nodes2.size(); ++i) {
        int v = nodes2[i];

        if (used_v.find(v) == used_v.end() && deg1[u] == deg2[v]) {
            bool consistent = true;

            for (int j = 0; j < node_index; ++j) {
                int u_prev = nodes1[j];
                if (current_P.count(u_prev) == 0) continue;

                int v_prev = current_P[u_prev];
                bool edge1 = adj1[u].count(u_prev);
                bool edge2 = adj2[v].count(v_prev);

                if (edge1 != edge2) {
                    consistent = false;
                    break;
                }
            }

            if (consistent) {
                current_P[u] = v;
                used_v.insert(v);

                if (find_isomorphism(nodes1, nodes2, current_P, used_v, node_index + 1))
                    return true;

                used_v.erase(v);
                current_P.erase(u);
            }
        }
    }
    return false;
}

// --- Find All Simple Cycles ---
void find_all_cycles() {
    for (set<int>::iterator it = V.begin(); it != V.end(); ++it) {
        int start_node = *it;
        vector<int> path;
        set<int> path_set;

        function<void(int)> dfs_cycle = [&](int u) {
            path.push_back(u);
            path_set.insert(u);

            for (set<int>::iterator jt = adj1[u].begin(); jt != adj1[u].end(); ++jt) {
                int v = *jt;
                if (v == start_node) {
                    if (path.size() >= 3) {
                        vector<int> cycle = path;
                        auto min_it = min_element(cycle.begin(), cycle.end());
                        rotate(cycle.begin(), min_it, cycle.end());
                        simple_cycles.insert(cycle);
                    }
                } else if (path_set.find(v) == path_set.end() && path.size() <= V.size()) {
                    dfs_cycle(v);
                }
            }

            path.pop_back();
            path_set.erase(u);
        };

        dfs_cycle(start_node);
    }
}

// --- BFS for Minimum Steps ---
int solve_bfs() {
    map<int, int> start_perm;
    for (set<int>::iterator it = V.begin(); it != V.end(); ++it)
        start_perm[*it] = *it;

    if (start_perm == target_P)
        return 0;

    queue<pair<map<int, int>, int>> q;
    set<map<int, int>> visited;

    q.push(make_pair(start_perm, 0));
    visited.insert(start_perm);

    while (!q.empty()) {
        pair<map<int, int>, int> front_element = q.front();
        map<int, int> current_perm = front_element.first;
        int dist = front_element.second;
        q.pop();

        for (set<vector<int>>::iterator it = simple_cycles.begin(); it != simple_cycles.end(); ++it) {
            const vector<int>& cycle = *it;
            map<int, int> rotation_map;
            for (size_t i = 0; i < cycle.size(); ++i)
                rotation_map[cycle[i]] = cycle[(i + 1) % cycle.size()];

            map<int, int> next_perm;
            for (set<int>::iterator node_it = V.begin(); node_it != V.end(); ++node_it) {
                int node = *node_it;
                int current_loc = current_perm[node];
                if (rotation_map.count(current_loc))
                    next_perm[node] = rotation_map[current_loc];
                else
                    next_perm[node] = current_loc;
            }

            if (next_perm == target_P)
                return dist + 1;

            if (visited.find(next_perm) == visited.end()) {
                visited.insert(next_perm);
                q.push(make_pair(next_perm, dist + 1));
            }
        }
    }

    return -1;
}

// --- Main Function ---
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int E;
    cin >> E;

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj1[u].insert(v);
        adj1[v].insert(u);
        V.insert(u);
        V.insert(v);
        deg1[u]++;
        deg1[v]++;
    }

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj2[u].insert(v);
        adj2[v].insert(u);
        V.insert(u);
        V.insert(v);
        deg2[u]++;
        deg2[v]++;
    }

    vector<int> nodes1(V.begin(), V.end());
    vector<int> nodes2(V.begin(), V.end());
    map<int, int> current_P;
    set<int> used_v;

    bool ok = find_isomorphism(nodes1, nodes2, current_P, used_v, 0);
    if (!ok) {
        cout << "No isomorphism found\n";
        return 0;
    }

    find_all_cycles();
    cout << solve_bfs() << endl;
    return 0;
}
