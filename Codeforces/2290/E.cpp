#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n+1);
    for (int i=1; i<=n; ++i) cin >> a[i];

    bool turn = true;
    ll sum = 0;
    int i=n;
    while (i >= 1 && a[i] == 0) {
        --i;
    }

    for (; i >= 0; --i) {
        sum -= a[i];
        sum += a[i] * min(k, i-1);
        if (sum % 2 != 0) turn = !turn;
    }

    cout << (sum % 2 == 0 && turn ? "Bob" : "Alice") << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}