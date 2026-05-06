#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dp(n, vector<ll>(m+1));

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if (num == 0) {
            for (int j = 1; j <= m; ++j) {
                if (i == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j];
                    if (j - 1 >= 1) dp[i][j] += dp[i-1][j-1];
                    if (j + 1 <= m) dp[i][j] += dp[i-1][j+1];
                    dp[i][j] %= M;
                }
            }
        } else {
            if (i == 0) dp[i][num] = 1;
            else {
                dp[i][num] = dp[i-1][num];
                if (num - 1 >= 1) dp[i][num] += dp[i-1][num-1];
                if (num + 1 <= m) dp[i][num] += dp[i-1][num+1];
                dp[i][num] %= M;
            }
        }
        
    }

    ll res = 0;

    for (int i = 1; i <= m; i++) (res += dp[n-1][i]) %= M;

    cout << res << "\n";
}