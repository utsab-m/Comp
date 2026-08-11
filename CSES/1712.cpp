#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll power(ll a, ll b, int M) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) (res *= a) %= M;
        (a *= a) %= M;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;

        cout << power(a, (power(b, c, MOD-1)), MOD) << '\n';
    }
}