#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    // We will store intersection points (C adjacent to R)
    vector<pair<int, int>> intersect;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'C') {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (isValid(ni, nj) && grid[ni][nj] == 'R') {
                        intersect.push_back({i, j});
                        break;
                    }
                }
            }
        }
    }

    // If there are no intersections, 0 switches needed
    if (intersect.empty()) {
        cout << 0;
        return 0;
    }

    // Build adjacency between intersecting cables
    // This helps identify independent wrapped sections
    map<pair<int,int>, vector<pair<int,int>>> adj;
    set<pair<int,int>> vis;

    for (auto &p : intersect) {
        int x = p.first, y = p.second;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny) && grid[nx][ny] == 'C') {
                adj[{x,y}].push_back({nx,ny});
            }
        }
    }

    int components = 0;

    function<void(int,int)> dfs = [&](int x, int y){
        vis.insert({x,y});
        for (auto nxt : adj[{x,y}]) {
            if (!vis.count(nxt)) dfs(nxt.first, nxt.second);
        }
    };

    for (auto &p : intersect) {
        if (!vis.count(p)) {
            dfs(p.first, p.second);
            components++;
        }
    }

    cout << components << "\n";
    return 0;
}
