#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;

    int numFrogs = 0;
    for (int i=1; i<=2*n; ++i) {
        char c; cin >> c;
        if (c == 'f') ++numFrogs;
    }

    cout << ((numFrogs % 2 == 0) ? 0 : 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}