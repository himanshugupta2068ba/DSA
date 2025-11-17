#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <limits>
#include <set>

using namespace std;

typedef long long int64;
const int64 INF = numeric_limits<int64>::max();

// 8 possible moves (dr, dc): all neighbors including diagonals
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// State for priority queue: {total_cost, row, col}
typedef tuple<int64, int, int> State;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];

    int start_r, start_c, end_r, end_c;
    cin >> start_r >> start_c;
    cin >> end_r >> end_c;
    start_r--; start_c--;
    end_r--; end_c--;

    int K;
    cin >> K;
    set<pair<int, int>> blocked_cells;
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        blocked_cells.insert(make_pair(r - 1, c - 1));
    }

    vector<vector<int64>> dist(N, vector<int64>(M, INF));
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[start_r][start_c] = 0;
    pq.push(make_tuple(0, start_r, start_c));

    while (!pq.empty()) {
        int64 current_cost;
        int r, c;
        tie(current_cost, r, c) = pq.top();
        pq.pop();

        if (current_cost > dist[r][c]) continue;

        if (r == end_r && c == end_c) {
            cout << current_cost << "\n";
            return 0;
        }

        int V_curr = grid[r][c];

        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M &&
                blocked_cells.find(make_pair(nr, nc)) == blocked_cells.end()) {
                
                int V_neighbor = grid[nr][nc];

                int V_max_other = -1;
                for (int j = 0; j < 8; ++j) {
                    if (i == j) continue;
                    int or_ = r + dr[j];
                    int oc_ = c + dc[j];

                    if (or_ >= 0 && or_ < N && oc_ >= 0 && oc_ < M &&
                        blocked_cells.find(make_pair(or_, oc_)) == blocked_cells.end()) {
                        V_max_other = max(V_max_other, grid[or_][oc_]);
                    }
                }

                int64 V_to_beat = max((int64)V_curr, (int64)V_max_other);
                int64 V_new = V_to_beat + 1;
                int64 move_cost = max(0LL, V_new - V_neighbor);
                int64 new_total_cost = current_cost + move_cost;

                if (new_total_cost < dist[nr][nc]) {
                    dist[nr][nc] = new_total_cost;
                    pq.push(make_tuple(new_total_cost, nr, nc));
                }
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
