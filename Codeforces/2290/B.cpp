#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<char> a(n+1);
    a[0] = 'B';
    int ans = 0;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        if (a[i] == a[i-1]) ++ans;
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}