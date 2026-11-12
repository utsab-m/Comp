#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> nums(m, vector<int>(n));

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> nums[j][i];
        }
    }

    for (ll i=0; i<m; ++i) sort(nums[i].begin(), nums[i].end());

    ll ans = 0;

    for (ll i=0; i<m; ++i) {
        for (ll j=0; j<n; ++j) {
            ans += (j - (n-1-j)) * nums[i][j];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}