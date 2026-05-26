#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7, MAX = 1000005;
ll factorial[MAX], invFactorial[MAX];

ll power(ll base, ll exp) {
    base %= MOD;

    ll res = 1;

    while (exp > 0) {
        if (exp % 2 == 1) (res *= base) %= MOD;
        (base *= base) %= MOD;
        exp /= 2;
    }

    return res;
}

ll aCb(ll a, ll b) {
    if (a <= 0 || b > a) return 0;
    return (factorial[a] * invFactorial[b] % MOD * invFactorial[a-b] % MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    factorial[0] = 1;
    for (int i = 1; i < MAX; i++) {
        (((factorial[i] = factorial[i-1] * i) %= MOD) += MOD) %= MOD;
    }

    invFactorial[MAX-1] = power(factorial[MAX-1], MOD-2);
    for (int i = MAX-2; i >= 0; i--) {
        invFactorial[i] = (invFactorial[i+1] * (i+1)) % MOD;
    }

    while (n--) {
        int a, b;
        cin >> a >> b;

        cout << aCb(a, b) << "\n";
    }
}