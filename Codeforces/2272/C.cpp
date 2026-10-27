#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int& ai: a) cin >> ai;

    int ans = 1;
    set<pair<int, int>> pairs;
    pairs.insert({a[0], a[1]});
    pairs.insert({a[n-2], a[n-1]});

    for (int i=1; i<n-1; ++i) {
        if (a[i+1] - a[i] > a[i] - a[i-1]) {
            pairs.insert({a[i-1], a[i]});
        } else {
            pairs.insert({a[i], a[i+1]});
        }
    }

    map<int, int> distCount;

    for (auto pr: pairs) {
        int dist = pr.second - pr.first;
        ++distCount[dist];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto [key, val]: distCount) {
        for (int i=0; i<val; ++i) {
            pq.push(key);
            if (pq.size() > x) pq.pop();
        }
    }

    while (pq.size()) {
        int top = pq.top();
        --distCount[top];
        ++distCount[(int)ceil(top / 2.0)];
        pq.pop();
    }
    
    for (auto [key, val]: distCount) {
        if (val > 0) {
            ans = max(ans, key);
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