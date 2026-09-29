#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n;
    cin >> n;

    map<ll, ll> cx, cy, c_diff, c_sum;

    for (int i=0; i<n; ++i) {
        int x, y;
        cin >> x >> y;

        cx[x]++;
        cy[y]++;
        c_diff[x - y]++;
        c_sum[x + y]++;
    }

    ll ans = 0;

    auto add_pairs = [&](const map<ll, ll>& m) {
        for (auto const& [key, count]: m) ans += count * (count-1);
    };

    add_pairs(cx); add_pairs(cy); add_pairs(c_diff); add_pairs(c_sum);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}