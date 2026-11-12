#include "bits/stdc++.h"
#include <numeric>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), g(n);
    for (int& ai: a) cin >> ai;
    for (int& bi: b) cin >> bi;
    if (n == 0) g[0] = a[0];
    else {
        for (int i = 0; i < n-1; ++i) g[i] = gcd(a[i], a[i+1]);
        g[n-1] = gcd(a[n-2], a[n-1]);
    }

    int ops = 0;

    if (n >= 2) {
        if (g[0] < b[0]) ++ops;
    }

    for (int i=0; i<n-2; ++i) {
        int A = g[i], B = g[i+1];
        if (lcm(A, B) < b[i+1]) {
            ++ops;
        }
    }

    if (n >= 2) {
        if (g[n-1] < b[n-1]) ++ops;
    }

    cout << ops << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}