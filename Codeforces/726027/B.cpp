#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, x; cin >> n >> x;

    ll maxLength = 0;

    vector<int> a(n+1), pref(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        pref[i] = a[i] + pref[i-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}