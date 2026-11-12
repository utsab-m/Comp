#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    map<int, vector<int>> distances;
    map<int, int> lastSeen;

    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        distances[x].push_back(i - lastSeen[x]);
        lastSeen[x] = i;
    }

    int ans = 2e5;

    for (int i=1; i<=k; ++i) {
        distances[i].push_back(n+1 - lastSeen[i]);
        sort(distances[i].rbegin(), distances[i].rend());
        ans = min(ans, max((int)ceil((distances[i][0] - 2) / 2.0), distances[i][1]-1));
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}