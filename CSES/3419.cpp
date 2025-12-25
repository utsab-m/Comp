#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    unordered_map<int, unordered_set<int>> row, col;

    vector<vector<int>> matrix(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        matrix[0][i] = i;
        col[i].insert(i);
    }
    for (int i = 0; i < n; i++) {
        matrix[i][0] = i;
        row[i].insert(i);
    }
    for (int i = 0; i < n; i++) {
        matrix[i][i] = 0;
        row[i].insert(0);
        col[i].insert(0);
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (matrix[r][c] == -1) {
                bool valid = false;
                int num = 0;

                while (!valid) {
                    num++;
                    valid = (row[r].find(num) == row[r].end() && col[c].find(num) == col[c].end());
                }

                matrix[r][c] = num;
                row[r].insert(num);
                col[c].insert(num);

            }
        }
    }

    for (auto row: matrix) {
        for (auto col: row) {
            cout << col << " ";
        }
        cout << "\n";
    }
}