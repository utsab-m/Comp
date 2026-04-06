#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool is_prime(ll x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

ll next_prime(ll x) {
    x++;
    while (!is_prime(x)) x++;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> primes(n);
        ll prime = 3;
        for (int i = 0; i < n-1; i++) {
            primes[i] = prime;
            prime = next_prime(prime);
        }

        vector<ll> res(n);
        
        cout << primes[0] << " ";

        for (int i = 1; i <= n-2; i++) {
            cout << primes[i-1] * primes[i] << " ";
        }

        cout << primes[n-2] << "\n";
    }
}