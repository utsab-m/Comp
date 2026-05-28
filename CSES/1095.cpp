#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll power(ll a, ll b) {
    if (b == 0) return 1;
    ll res = 1;

    while (b > 0) {
        if (b & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        cout << power(a, b) << "\n";
    }
}