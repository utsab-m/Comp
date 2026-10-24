#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n), lastIndex(n+2, -1);

    for (int i=0; i<n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    for (int i=0; i<n; ++i) lastIndex[a[i]] = i;

    int mex = 0, numOps = 1;
    while (true) {
        int last = lastIndex[mex];
        if (numOps*k <= last+1) {
            ++mex;
        }
        else break;
        ++numOps;
    }

    cout << mex << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}