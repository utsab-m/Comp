#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    ll n, l, r; cin >> n >> l >> r;

    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i=0; i<n/2; ++i) {
        ans -= a[i];
        ans += a[n-i-1];
    }

    if (n % 2 == 1) {
        ans = max({ans, ans + a[n/2] - r, ans, ans + l - a[n/2]});
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}