#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        ll m; cin >> m;

        for (int i=1; i<=n-1; ++i) {
            ll x; cin >> x;

            if (x >= m) m = x;
            else m += x;
        }

        cout << m << '\n';
    }
}