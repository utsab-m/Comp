#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> dp(N+1, vector<int>(3)); 

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            int happiness;
            cin >> happiness;

            for (int k = 0; k < 3; ++k) {
                if (k != j) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + happiness);
                }
            }
        }
    }

    int res = 0;

    for (int i = 0; i < 3; i++) res = max(res, dp[N][i]);

    cout << res << '\n';
}