#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll fact[2000], inv[2000];

ll power(ll b, ll e) {
    if (b == 0) return 0;
    
    ll res = 1;

    while (e > 0) {
        if (e & 1) (res *= b) %= MOD;
        (b *= b) %= MOD;
        e /= 2;
    }

    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < 2000; i++) {
        (fact[i] = i * fact[i-1]) %= MOD;
    }
    inv[1999] = power(fact[1999], MOD-2);
    for (int i = 1998; i >= 0; i--) {
        (inv[i] = (i+1) * inv[i+1]) %= MOD;
    }
}

ll ncr(int a, int b) {
    return (fact[a] * inv[b] % MOD * inv[a-b] % MOD) % MOD; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // (2m + n - 1) choose n
    precompute();
    cout << ncr(2*m+n-1, n-1) << "\n";

}