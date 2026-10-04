#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

const ll CYC[8] = {4, 16, 37, 58, 89, 145, 42, 20};
int t, n;
ll cnt[9];

int sig(ll x) {
    ll s=0;
    while (true) {
        if (x == 1) return 8;
        for (int k=0; k<8; ++k) {
            if (x == CYC[k]) return ((k-s) % 8 + 8) % 8;
        }
        ll y=0;
        while (x > 0) { ll r = x%10; y += r * r; x /= 10; }
        x = y;
        ++s;
    }
}

void solve() {
    cin >> n;

    for (int i=0; i<9; ++i) cnt[i] = 0;

    for (int i=0; i<n; ++i) {
        ll a; cin >> a;
        ++cnt[sig(a)];
    }

    ll res = 0;

    for (int i=0; i<9; ++i) res += cnt[i] * (cnt[i]-1) / 2;

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        solve();
    }
}