#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;

    vector<int> a(n+1), v(n+1);
    map<int, int> freq;

    for (int i=1; i<=n; ++i) {
        cin >> a[i];
    }

    for (int i=1; i<=n-4; ++i) {
        v[i] = a[i] + a[i+2] - a[i+4];
        ++freq[v[i]];
    }

    ll ans = 0;

    for (const auto& [love, count]: freq) {
        ans += 1LL * count * (count-1) / 2;
    }

    for (int i=1; i<=n-4; ++i) {
        if (i+2 <= n-4 && v[i] == v[i+2]) --ans;
        if (i+4 <= n-4 && v[i] == v[i+4]) --ans;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}