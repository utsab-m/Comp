#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n+1), b(m+1);
    vector<ll> pref(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        pref[i] = a[i] + pref[i-1];
    }
    for (int i=0; i<m; ++i) cin >> b[i];
    sort(b.begin(), b.end());

    ll res = 0;

    for (int i=0; i<m; ++i) {
        ll bi = b[i]+1, bj = b[i+1];
        res += abs(pref[bj] - pref[bi-1]);
    }

    res += pref[n] - pref[b[m]];

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}