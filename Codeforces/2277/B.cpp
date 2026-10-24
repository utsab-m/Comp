#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;

    bool isZero = false;
    int mn = INT_MAX;

    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        mn = min(mn, a);
        if (a == 0) isZero = true;
    }

    if (isZero || n-1 >= mn) cout << n << '\n';
    else cout << 0 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}