#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;

    if (__gcd(n, m) <= 2 && __gcd(a, n) == 1 && __gcd(b, m) == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}