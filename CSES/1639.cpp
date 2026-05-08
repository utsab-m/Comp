#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
    dp[0][0] = 0;

    for (int r = 0; r <= n; r++) {
        for (int c = 0; c <= m; c++) {
            if (r != 0) {
                dp[r][c] = min(dp[r][c], dp[r-1][c] + 1);
            }

            if (c != 0) {
                dp[r][c] = min(dp[r][c], dp[r][c-1] + 1);
            }

            if (r != 0 && c != 0) {
                int new_cost = dp[r-1][c-1] + (s1[r-1] != s2[c-1]);
                dp[r][c] = min(dp[r][c], new_cost);
            }
        }
    }

    cout << dp[n][m] << "\n";
}