#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int N = 2e5;
vector<int> pf[N+1];
vector<bool> cmp(N+1);

void pre() {
    for (int i=2; i<=N; ++i) {
        if (!cmp[i]) {
            for (int j=i; j<=N; j+=i) {
                cmp[j] = true;
                pf[j].push_back(i);
            }
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;

    vector<ll> dp(n+1, 1e18);

    for (int i=1; i<=k; ++i) dp[i] = 0;

    for (int i=k+1; i<=n; ++i) {
        for (auto p: pf[i]) {
            dp[i] = min(dp[i], 1+p*dp[i/p]);
        }
    }

    ll ans = 0;

    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        ans += dp[a];
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pre();

    int t; cin >> t;
    while (t--) solve();
}