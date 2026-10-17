#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q; cin >> n >> q;

    vector<ll> a(n+1);
    vector<vector<ll>> dp(n, vector<ll>(2));
    
    for (ll i=1; i<=n; ++i) cin >> a[i];

    dp[n-1][0] = dp[n-1][1] = a[n];

    for (ll i=n-2; i>=0; --i) {
        ll num = a[i+1];
        dp[i][0] = dp[i][1] = num;
        // // max sum beginning at index i+2 (contiguous)
        // int maxContSum = dp[i+1][0];
        // // max sum beginning at or after index i+2
        // int maxSumAfter = dp[i+1][1];
        // // choice add curr num to max subarray beginning at x+2
        // // max sum of curr subarray beginning at index i+1
        // dp[i][0] = max(dp[i][0], num+maxContSum);
        // // max sum at or after index i+1
        // dp[i][1] = max()

        dp[i][0] = max(dp[i][0], num + dp[i+1][0]);
        dp[i][1] = max(dp[i][1], dp[i][0]);
        dp[i][1] = max(dp[i][1], dp[i+1][0]);
        dp[i][1] = max(dp[i][1], dp[i+1][1]);
    }

    for (ll i=1; i<=q; ++i) {
        ll x; cin >> x;
        cout << max(dp[x][0], dp[x][1]) << '\n';
    }
}