#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n+1), p(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        (p[i] = p[i-1] + a[i]) %= k;
    }

    ll ans = 0;
    int l=0, r=k+1;
    map<int, int> cnt;

    while (r <= n) {
        int left = p[l], right = p[r];
        ++cnt[left];
        // we count how many stuff is equal to what is at the right pointer
        ans += cnt[right];
        ++l;
        ++r;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}