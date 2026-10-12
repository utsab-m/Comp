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

    int a=0, b=0;
    int mex_a=INT_MAX, mex_b=INT_MAX;

    for (const auto& [card, count]: cnt) {
        int alice_count = (a==b) ? ceil(count/2.0) : floor(count/2.0);
        int bob_count = count - alice_count;

        a += alice_count; b += bob_count;

        if (card < mex_a && alice_count < k) mex_a = card;
        if (card < mex_b && bob_count < k) mex_b = card;
    }

    cout << ((mex_a == mex_b) ? "NO" : "YES") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}