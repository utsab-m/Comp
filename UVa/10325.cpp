#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<int> lotteries(m);

        for (int& lottery: lotteries) cin >> lottery;

        ll res = 0;

        for (int mask = 1; mask < (1 << m); mask++) {
            ll current_lcm = 1, element_count = 0;
            bool overflow = false;

            for (int i = 0; i < m; i++) {
                if ((mask >> i) & 1) {
                    element_count++;
                    current_lcm = lcm(current_lcm, lotteries[i]);
                }

                if (current_lcm > n) {
                    overflow = true;
                    break;
                }
            }

            if (overflow) continue;

            int sign = (element_count % 2 == 1) ? 1 : -1;
            res += sign * (n / current_lcm);
        }

        cout << n - res << "\n";
    }

    
}