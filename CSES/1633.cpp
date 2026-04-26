#include "bits/stdc++.h"
using namespace std;
using ll = unsigned long long;

int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> dp(n+1, 1);

    for (int i = 2; i <= n && i <= 6; i++) {
        dp[i] = 2 * dp[i-1];
    }

    for (int i = 7; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % mod;
    }

    cout << dp[n] << "\n";
}