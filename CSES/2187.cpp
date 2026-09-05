#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7, MAXN = 1e6;
ll fac[MAXN+1], invFac[MAXN+1];

ll power(ll b, ll e) {
    ll res = 1;
    (res %= MOD);

    while (e > 0) {
        if (e % 2 == 1) (res *= b) %= MOD;
        (b *= b) %= MOD;
        e /= 2;
    }

    return res;
}

ll mod_inverse(ll n) {
    return power(n, MOD-2);
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; ++i) (fac[i] = i * fac[i-1]) %= MOD;

    invFac[MAXN] = mod_inverse(fac[MAXN]);
    for (int i = MAXN-1; i >= 0; --i) (invFac[i] = (i+1) * invFac[i+1]) %= MOD;
}

ll ncr(ll n, ll r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return fac[n] * invFac[n-r] % MOD * invFac[r] % MOD;
}

bool valid_prefix(string& prefix) {
    int pos = 0;
    for (char c: prefix) {
        if (c == '(') {
            ++pos;
        } else {
            --pos;
        }
        if (pos < 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string prefix;
    cin >> prefix;

    if (!valid_prefix(prefix) || n % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int left = 0, right = 0;
    for (char& c: prefix) {
        if (c == '(') ++left;
        else ++right;
    }

    left = n/2 - left;
    right = n/2 - right;

    precompute();

    cout << (ncr(left+right, right) - ncr(left+right, left-1) + MOD) % MOD << '\n';
}