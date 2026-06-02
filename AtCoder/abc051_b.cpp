#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll nc2(ll n) {
    if (n < 0) return 0;
    return n * (n-1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, s;
    cin >> k >> s;

    int fac[] = {1, 3, 3, 1};

    ll res = 0;

    for (int i = 0; i < 4; i++) {
        res += ((i % 2 == 0) ? 1 : -1) * fac[i] * nc2(s - i * (k+1) + 2);
    }

    cout << res << "\n";
}