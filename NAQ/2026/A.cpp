#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll power(ll b, ll e) {
    ll res = 1;
    while (e > 0) {
        if (e % 2 == 1) (res *= b) %= MOD;
        (b *= b) %= MOD;
        e /= 2;
    }
    return res % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    cout << (n % MOD * (n+1) % MOD * (n+2) % MOD * power(6, MOD-2) % MOD) + MOD % MOD << '\n';
}