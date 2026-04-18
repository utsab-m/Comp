#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> primes;
    vector<int> table((int)1e6+1);
    table[1] = 1;
    primes.push_back(2);

    for (int i = 2; i < (int)1e6+1; i++) {
        int j = i;
        int factors = 1;
        for (int prime: primes) {
            int curr = 1;
            while (j % prime == 0) {
                j /= prime;
                curr++;
            }
            factors *= curr;
        }
        if (factors == 1) {
            factors++;
            primes.push_back(i);
        }
        table[i] = factors;
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        
        cout << table[x] << "\n";
    }
}