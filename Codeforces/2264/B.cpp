#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;

    ll ans = LLONG_MIN, s = 0;

    priority_queue<int, vector<int>> pq;

    for (int i=1; i<=n; ++i) {
        ll a; cin >> a;

        if (i >= m) {
            ans = max(ans, m * a - s);
            s += a;
            pq.push(a);
            s -= pq.top();
            pq.pop();
        } else {
            s += a;
            pq.push(a);
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