#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    int MAX = 3e5+1;
    vector<int> dp(n+1, MAX);
    set<int> nums;
    
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        nums.insert(x);
    }

    for (int i=1; i<=n; ++i) {
        if (nums.count(i)) {
            dp[i] = 1;
        } else {
            for (int j=2; j*j<=i; ++j) {
                if (i % j == 0 && (dp[j] != MAX && dp[i/j] != MAX)) {
                    dp[i] = min(dp[i], dp[j]+dp[i/j]);
                }
            }
        }
    }

    for (int i=1; i<=n; ++i) {
        if (dp[i] == MAX) cout << -1;
        else cout << dp[i];
        cout << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}