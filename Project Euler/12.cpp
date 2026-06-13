#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int count_divisors(ll n) {
    int divisors = 0;

    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ++divisors;
            if (i != n / i) ++divisors;
        }
    }

    return divisors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1, d = 1;

    while (count_divisors(t) <= 500) {
        ++d;
        t += d;
    }

    cout << t << "\n";
}