#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<ll> a(n+1);
    for (int i=1; i<=n; ++i) cin >> a[i];

    ll ans, L, H;
    ans = L = H = a[1];

    for (int i=2; i<=n; ++i) {
        ans = max({ans, a[i] - L, a[i] + H});
        L = min({a[i], a[i]+L, a[i]+2*L});
        H = max({a[i], a[i]+H, a[i]+2*H});
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}