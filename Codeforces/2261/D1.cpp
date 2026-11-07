#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;

    cout << n-1 << '\n';
    for (int i=1; i<n; ++i) {
        cout << i << ' ' << i << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}