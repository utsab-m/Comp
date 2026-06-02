#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> is_composite(3001);
    vector<int> primes;

    for (int i = 2; i <= 3000; i++) {
        if (!is_composite[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= 3000; j += i) {
                is_composite[j] = true;
            }
        }
    }

    int s = primes.size();
    ll res = 0;

    for (int i = 0; i < s; i++) {
        for (int j = i+1; j < s; j++) {
            int a = primes[i], b = primes[j];

            ll x = a;

            while (x <= n) {
                int y = b;
                while (x * y <= n) {
                    res++;
                    y *= b;
                }
                x *= a;
            }
        }
    }

    cout << res << "\n";
}