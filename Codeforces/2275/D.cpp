#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    ll n, k; cin >> n >> k;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> ch(n+1);

    for (int i=1; i<=n; ++i) {
        int a, b, c; cin >> a >> b >> c;

        pq.emplace(a+b+c, i);
        ch[i] = !(a == b && b == c);
    }

    ll s = 0;

    while (k > 0) {
        
    }

    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}