#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7, MAX = 2000005;

ll fac[MAX+1], inv[MAX+1];

ll power(ll b, ll e) {
    if (e == 0) return 1;
    ll u = power(b, e/2);
    (u *= u) %= MOD;
    if (e & 1) (u *= b) %= MOD;
    return u;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        (fac[i] = i * fac[i-1]) %= MOD;
    }

    inv[MAX] = power(fac[MAX], MOD-2);
    for (int i = MAX-1; i >= 0; i--) {
        (inv[i] = (i+1) * inv[i+1]) %= MOD;
    }
}

ll ncr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    return (fac[n] * inv[r] % MOD * inv[n-r] % MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    precompute();
    cout << ncr(m + n - 1, m) << "\n";
}