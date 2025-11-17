#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<vector<vector<int>>> sheet(R, vector<vector<int>>(C));
    int num = 1;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            sheet[i][j].push_back(num++);

    string fold;
    vector<string> folds;
    while (cin >> fold) folds.push_back(fold);

    int current_R = R, current_C = C;

    for (string f : folds) {
        char type = f[0];
        int k = stoi(f.substr(1));

        if (type == 'h') {
            // horizontal fold -> bottom over top
            int top = k;
            int bottom = current_R - k;
            int new_R = max(top, bottom);
            vector<vector<vector<int>>> new_sheet(new_R, vector<vector<int>>(current_C));

            // copy top
            for (int i = 0; i < top; ++i)
                new_sheet[i] = sheet[i];

            // fold bottom over top
            for (int i = 0; i < bottom; ++i) {
                int src = k + i;
                int dest = k - 1 - i;
                for (int j = 0; j < current_C; ++j) {
                    auto temp = sheet[src][j];
                    reverse(temp.begin(), temp.end());
                    if (dest >= 0) {
                        new_sheet[dest][j].insert(new_sheet[dest][j].end(), temp.begin(), temp.end());
                    } else {
                        new_sheet[i][j] = temp;
                    }
                }
            }
            sheet = new_sheet;
            current_R = new_R;
        } 
        else if (type == 'v') {
            // vertical fold -> right over left
            int left = k;
            int right = current_C - k;
            int new_C = max(left, right);
            vector<vector<vector<int>>> new_sheet(current_R, vector<vector<int>>(new_C));

            // copy left
            for (int i = 0; i < current_R; ++i)
                for (int j = 0; j < left; ++j)
                    new_sheet[i][j] = sheet[i][j];

            // fold right over left
            for (int j = 0; j < right; ++j) {
                int src = k + j;
                int dest = k - 1 - j;
                for (int i = 0; i < current_R; ++i) {
                    auto temp = sheet[i][src];
                    reverse(temp.begin(), temp.end());
                    if (dest >= 0) {
                        new_sheet[i][dest].insert(new_sheet[i][dest].end(), temp.begin(), temp.end());
                    } else {
                        new_sheet[i][j] = temp;
                    }
                }
            }
            sheet = new_sheet;
            current_C = new_C;
        }
    }

    // final stack is at sheet[0][0]
    cout << sheet[0][0].back() << " " << sheet[0][0].front() << "\n";
    return 0;
}
