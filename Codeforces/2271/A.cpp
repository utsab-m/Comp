#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int a, b; cin >> a >> b;

    if (b > a+1) {
        cout << -1 << '\n';
        return;
    }

    cout << ((a%2 == b%2) ? a : a+1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}