#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n+1);
    for (int i=1; i<=n; ++i) cin >> a[i];

    ll sum = 0;

    for (int i=k; i<=n-k+1; ++i) {
        sum += a[i];
    }

    int pairs_to_process = min(k-1, n-k+1);

    for (int i=1; i<=pairs_to_process; ++i) {
        sum += max(a[i], a[n-i+1]);
    }

    cout << sum << '\n';
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