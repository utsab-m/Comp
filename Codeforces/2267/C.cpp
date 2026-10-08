#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int N = 3e5;

int n, x, a[N+12];
ll cnt[N+12];
vector<bool> comp(N+12);
vector<int> pf[N+12];

void solve() {
    cin >> n >> x;

    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        int r = a[i];
        a[i] = __gcd(a[i], x);

        for (auto j: pf[a[i]]) {
            cnt[j] += r;
        }
    }
    ll ans = 0;

    for (auto j: pf[x]) {
        ans = max(ans, cnt[j]);
    }
    for (int i=1; i<=n; ++i) {
        for (auto j: pf[a[i]]) cnt[j] = 0;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i=2; i<=N; ++i) {
        if (!comp[i]) {
            for (int j=i; j<=N; j+=i) {
                comp[j] = true;
                pf[j].push_back(i);
            }
        }
    }

    int t; cin >> t;
    while (t--) solve();
}