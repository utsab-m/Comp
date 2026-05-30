#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MAX = 2000000;

set<int> primes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll sum = 0;

    for (int i = 2; i < MAX; i++) {
        primes.insert(i);
    }

    for (int i = 2; i < MAX; i++) {
        if (primes.find(i) != primes.end()) {
            sum += i;
            for (int j = i; j < MAX; j += i) {
                primes.erase(j);
            }
        }
    }

    cout << sum << "\n";
}