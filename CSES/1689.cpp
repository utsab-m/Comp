#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

vector<pair<int, int>> dir = {
    {2, 1},
    {-2, 1},
    {1, 2},
    {1, -2},
    {2, -1},
    {-2, -1},
    {-1, 2},
    {-1, -2}
};

vector<vector<int>> grid(8, vector<int>(8, 0));

bool inb(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool backtrack(int x, int y, int curr) {
    grid[x][y] = curr;
    if (curr == 64) return true;

    for (auto [dx, dy]: dir) {
        int nx = x + dx, ny = y + dy;
        if (inb(nx, ny) && grid[nx][ny] == 0) {
            if (backtrack(nx, ny, curr+1)) {
                return true;
            }
        }
    }

    grid[x][y] = 0;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    backtrack(x, y, 1);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}