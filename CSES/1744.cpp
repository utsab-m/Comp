#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, (int)1e9));

    for (int r = 1; r <= a; r++) {
        for (int c = 1; c <= b; c++) {
            if (r != c) {
                // Horizontal
                for (int i = 1; i <= r-1; i++) {
                    dp[r][c] = min(dp[r][c], dp[i][c] + dp[r-i][c] + 1);
                }
                // Vertical
                for (int j = 1; j <= b-1; j++) {
                    dp[r][c] = min(dp[r][c], dp[r][j] + dp[r][c-j] + 1);
                }
            } else {
                dp[r][c] = 0;
            }
        }
    }

    cout << dp[a][b] << "\n";
}