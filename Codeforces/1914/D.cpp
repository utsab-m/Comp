#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n), b(n), c(n);
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        a[i] = {x, i};
    }

    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        b[i] = {x, i};
    }

    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        c[i] = {x, i};
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int res = 0;

    for (int i=1; i<=3; ++i) {
        for (int j=1; j<=3; ++j) {
            for (int k=1; k<=3; ++k) {
                int ai=n-i, bi=n-j, ci=n-k;
                int x=a[ai].second, y=b[bi].second, z=c[ci].second;
                if (x != y && y != z && x != z) {
                    res = max(res, a[ai].first+b[bi].first+c[ci].first);
                }
            }
        }
    }

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}