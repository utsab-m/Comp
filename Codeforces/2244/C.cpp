#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    bool res = true;

    for (int i=1; i<=n; ++i) {
        int p; cin >> p;
        res = res && (abs(p - i) % __gcd(x, y)) == 0;
    }

    cout << (res ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}