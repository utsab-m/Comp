#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;

    map<int, int> cnt;

    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        ++cnt[a];
    }

    bool win = false;
    for (int x=0; x<=n; ++x) {
        if (cnt[x] < 2*k) {
            win = (cnt[x] == 2*k-1);
            break;
        }
    }
    
    cout << (win ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}