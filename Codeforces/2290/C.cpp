#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> h(n);
    for (int i=0; i<n; ++i) cin >> h[i];
    sort(h.begin(), h.end());
    vector<int> shelf(n);
    int l=0, r=n-1;
    int i=0;
    while (i<n) {
        shelf[l] = h[i];
        ++l;
        if (i+1<n) {
            shelf[r] = h[i+1];
            --r;
        }
        i += 2;
    }

    int ans = 0;
    if (n == 1) ans = 1;
    else ans = 2;
    for (int i=1; i<n-1; ++i) {
        if (shelf[i] > shelf[i-1] || shelf[i] > shelf[i+1]) ++ans;
    }

    cout << ans << '\n';
    for (int book: shelf) cout << book << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}