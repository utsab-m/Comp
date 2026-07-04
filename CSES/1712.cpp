#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll power(ll a, ll b, int m) {
    if (b == 0) return 1;
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) (res *= a) %= m;
        (a *= a) %= m;
        b /= 2;
    }
    return res;
}

ll power(ll a, ll b, ll c) {
    ll res = power(b, c, MOD-1);
    res = power(a, res, MOD);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        cout << power(a, b, c) << "\n";
    }
}