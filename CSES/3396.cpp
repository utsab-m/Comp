#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int MAX = 1e6+1;
vector<int> primes;
vector<bool> is_composite(MAX);

void sieve() {
    for (ll num = 2; num < MAX; ++num) {
        if (!is_composite[num]) {
            primes.push_back(num);
            for (ll comp = num * num; comp < MAX; comp += num) is_composite[comp] = true;
        }
    }
}

bool is_prime(ll num) {
    if (num < 2) return false;
    for (int prime: primes) {
        if (1LL * prime * prime > num) break;
        if (num % prime == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    sieve();

    while (t--) {
        ll n;
        cin >> n;
        ++n;

        while (!is_prime(n)) ++n;

        cout << n << '\n';
    }
}