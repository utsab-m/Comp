#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int INV2 = 5e8+4;

ll range_sum(ll l, ll r) {
    ll count =(r-l+1) % MOD;
    ll sum_lr = (l+r) % MOD;
    ll total = (count * sum_lr) % MOD;
    return (total * INV2) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll total_sum = 0;
    ll l = 1;

    while (l <= n) {
        ll q = n/l, r = n/q;

        ll sum_d = range_sum(l, r);
        ll term = (sum_d * (q % MOD)) % MOD;

        total_sum = (total_sum + term) % MOD;
        
        l = r+1;
    }

    cout << total_sum << '\n';
}