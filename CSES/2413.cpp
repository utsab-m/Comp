#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int M = 1e9+7;
ll dp[1000001][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= 1000000; i++) {
        (dp[i][0] += 2 * dp[i-1][0]) %= M;
        (dp[i][0] += dp[i-1][1]) %= M;
        (dp[i][1] += dp[i-1][0]) %= M;
        (dp[i][1] += 4 * dp[i-1][1]) %= M;
    }

    while (t--) {
        int n;
        cin >> n;

        cout << (dp[n][0] + dp[n][1]) % M << "\n";
    }
}