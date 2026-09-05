#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7, MAXN = 1e6;
ll fac[MAXN+1], invFac[MAXN+1];

ll power(ll b, ll e) {
    ll res = 1;
    b %= MOD;
    
    while (e > 0) {
        if (e % 2 == 1) (res *= b) %= MOD;
        e /= 2;
        (b *= b) %= MOD;
    }

    return res;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; ++i) (fac[i] = i * fac[i-1]) %= MOD;

    invFac[MAXN] = power(fac[MAXN], MOD-2);
    for (int i = MAXN-1; i >= 0; --i) (invFac[i] = (i+1) * invFac[i+1]) %= MOD;
}

ll ncr(ll n, ll r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return fac[n] * invFac[n-r] % MOD * invFac[r] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    precompute();

    if (n % 2 == 0) {
        n /= 2;
        cout << (ncr(2 * n, n) - ncr(2 * n, n+1) + MOD) % MOD << '\n';
    } else {
        cout << 0 << '\n';
    }
    
}