#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int D[5];
    D[0] = 1; D[1] = 0;
    for (int i = 2; i <= 4; ++i) D[i] = (i-1) * (D[i-1] + D[i-2]);
    
    ll dp[1001][5];
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 4; ++j) {
            if (i == j || j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    ll perms = 0;
    for (int i = 0; i <= k; i++) {
        perms += dp[n][i] * D[i];
    }

    cout << perms << "\n";
}