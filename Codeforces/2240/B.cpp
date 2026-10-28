#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 998244353;

ll exp(ll b, ll e, ll m) {
    e %= m-1;
    ll res = 1;
    while (e > 0) {
        if (e % 2 == 1) (res *= b) %= m;
        e /= 2;
        (b *= b) %= m;
    }
    return res;
}

// ll exp(ll a, ll b, ll c) {

// }

void solve() {
    ll n, m, r, c; cin >> n >> m >> r >> c;
    ll ans = exp(2, r*c-1 + (r-1)*(m-c) + (c-1)*(n-r), MOD);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}