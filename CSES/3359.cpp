#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char>> grid(n+1, vector<char>(n+1));
    vector<vector<int>> dp(n+1, vector<int>(n+1, INF));
    vector<vector<string>> res(n+1, vector<string>(n+1));
    dp[1][1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            // Up
            if (i-1 >= 1) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + (grid[i][j] - grid[i-1][j]));
            }
            // Left
            if (j-1 >= 1) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + (grid[i][j] - grid[i][j-1]));
            }
        }
    }

    function<void(int, int)> printPath = [&](int i, int j) {
        cout << grid[i][j];
        if (i != n || j != n) {
            int right = dp[i][j+1], down = dp[i+1][j];

            if (down < right) {
                printPath(i+1, j);
            } else {
                printPath(i, j+1);
            }
        }
    };

    printPath(n, n);

    cout << "\n";
}