#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

vector<vector<int>> d = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

void dfs(int r, int c, vector<string>& grid, vector<vector<int>>& vis, int n, int m) {
    for (auto dir: d) {
        int dr = r + dir[0], dc = c + dir[1];
        if (dr < 0 || dc < 0 || dr >= n || dc >= m) continue;

        if (grid[dr][dc] == '.' && !vis[dr][dc]) {
            vis[dr][dc] = 1;
            dfs(dr, dc, grid, vis, n, m);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int rooms = 0;

    vector<string> grid(n);
    for (string& row: grid) cin >> row;

    vector<vector<int>> vis(n, vector<int>(m)); 

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                rooms++;
                dfs(i, j, grid, vis, n, m);
            }
        }
    }

    cout << rooms << '\n';
}