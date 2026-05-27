#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAX = 200005;
ll fact[MAX], invFact[MAX];

ll power(ll b, ll e) {
    if (b <= 0) return 0;
    if (e <= 0) return 1;

    ll res = 1;

    while (e > 0) {
        if (e % 2 == 1) (res *= b) %= MOD;
        (b *= b) %= MOD;
        e /= 2;
    }

    return res % MOD;
}

ll nCr(ll n, ll r) {
    return (fact[n] * invFact[r] % MOD * invFact[n - r] % MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        (fact[i] = fact[i-1] * i) %= MOD;
    }

    invFact[MAX-1] = power(fact[MAX-1], MOD-2);
    for (int i = MAX-2; i >= 0; i--) {
        (invFact[i] = invFact[i+1] * (i+1)) %= MOD;
    }

    ll res = (2 * nCr(2*n-1, n) % MOD) - n;

    cout << res << "\n";
}