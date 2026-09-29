#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int get_xor(int n) {
    if (n % 4 == 0) return n;
    else if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n+1;
    return 0;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int x = get_xor(a-1);
    int res;

    if (x == b) res = a;
    else if ((x ^ b) != a) res = a+1;
    else res = a+2;

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}