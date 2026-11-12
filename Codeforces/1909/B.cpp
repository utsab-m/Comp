#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool check(vector<ll>& a, ll MOD) {
    set<ll> distinct;
    for (ll x: a) {
        distinct.insert(x % MOD);
    }
    return distinct.size() == 2;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    
    bool odd = false, even = false;

    for (int i=0; i<n; ++i) {
        cin >> a[i];
        odd = odd || (a[i] % 2 != 0);
        even = even || (a[i] % 2 == 0);
    }

    if (n == 2) {
        ll ans = 1e18;
        cout << ans << '\n';
    } else {
        ll ans = 2;
        while (!check(a, ans)) {
            ans *= 2;
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}