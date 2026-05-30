#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MAX = 2000000;

vector<bool> primes(MAX+1, true);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll sum = 0;
    
    for (ll i = 2; i < MAX; i++) {
        if (primes[i]) {
            sum += i;
            for (ll j = i*i; j < MAX; j += i) {
                primes[j] = false;
            }
        }
    }

    cout << sum << "\n";
}