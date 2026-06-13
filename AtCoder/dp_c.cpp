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

    // Go through each day
    for (int i = 1; i <= N; ++i) {
        // Go through each choice for happiness for day i
        for (int j = 0; j < 3; ++j) {
            int happiness;
            cin >> happiness;

            // If we're on choice A for day i, day i-1 must be B or C
            // Basically just make sure we have the max between the possibilities from day i-1
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