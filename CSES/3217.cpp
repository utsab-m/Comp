#include <bits/stdc++.h>
using namespace std;

bool inbounds(int n, int r, int c) {
    return (r >= 0 && r < n) && (c >= 0 && c < n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int k = 0;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    vector<vector<bool>> seen(n, vector<bool>(n, false));

    q.push({0, 0});
    seen[0][0] = true;

    vector<pair<int, int>> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, 
                                    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    while (!q.empty()) {
        int size = q.size();
        for (int i=0; i<size; i++) {
            auto pos = q.front(); q.pop();
            int r = pos.first, c = pos.second;
            grid[r][c] = k;

            for (auto move: moves) {
                int dr = move.first, dc = move.second;
                int nr = r + dr, nc = c + dc;
                if (inbounds(n, nr, nc) && !seen[nr][nc]) {
                    q.push({nr, nc});
                    seen[nr][nc] = true;
                }
            }
        }
        k++;
    }

    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            cout << grid[r][c] << " ";
        }
        cout << "\n";
    }
}