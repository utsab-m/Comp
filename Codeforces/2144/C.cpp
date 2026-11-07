#include "bits/stdc++.h"
#include <array>
using namespace std;
using ll = long long;

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=1; i<=n; ++i) cin >> b[i];

    vector<array<ll, 2>> dp(n+1);
    dp[0][0] = dp[0][1] = 1;
    for (int i=1; i<=n; ++i) {
        if (a[i] >= a[i-1] && b[i] >= b[i-1]) {
            dp[i][0] += dp[i-1][0];
            dp[i][1] += dp[i-1][1];
        }
        if (a[i] >= b[i-1] && b[i] >= a[i-1]) {
            dp[i][0] += dp[i-1][1];
            dp[i][1] += dp[i-1][0];
        }
    }

    cout << (dp[n][0] + dp[n][1]) / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}