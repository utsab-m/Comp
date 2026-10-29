#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

bool check(vector<int>& a, vector<int>& b, int x, int y, int n) {
    for (int i=0; i<n; ++i) {
        if (a[(x+i)%n] >= b[(y+i)%n]) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i) cin >> b[i];
    for (int i=0; i<n; ++i) cin >> c[i];

    ll iCount=0, kCount=0;

    // checks every possible starter i and k for a and c respectively
    // if it's stable when a starts at i, then we count that as a pair (i, 1)
    // same thing for (1, k)
    for (int i=0; i<n; ++i) {
        if (check(a, b, i, 0, n)) ++iCount;
        if (check(b, c, 0, i, n)) ++kCount;
    }

    // cout << iCount.size() * kCount.size() + n-1 << '\n';
    cout << iCount * kCount * n << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}