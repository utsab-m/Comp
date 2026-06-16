#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    // dp[i][j] = max profit from a subset of items 1,2,...,i with a bag of capacity of j
    vector<vector<ll>> dp(N+1, vector<ll>(W+1));

    for (int i=1; i<=N; ++i) {
        int w, v;
        cin >> w >> v;

        for (int j=1; j<=W; ++j) {
            // Choose current item if item can fit
            if (j-w >= 0) dp[i][j] = max(dp[i][j], v + dp[i-1][j-w]);

            // Don't choose current item
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    
    cout << dp[N][W] << '\n';
}