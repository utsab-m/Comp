#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int M = 1e9+7, MAX = 1e6+1;

ll fac[MAX], inv[MAX];

bool check_excel(int sum, int a, int b) {
    while (sum > 0) {
        if (sum % 10 != a && sum % 10 != b) return false;
        sum /= 10;
    }
    return true;
}

ll power(ll b, ll e) {
    if (b == 0) return 0;
    ll res = 1;
    while (e > 0) {
        if (e & 1) (res *= b) %= M;
        (b *= b) %= M;
        e /= 2;
    }
    return res;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < MAX; i++) (fac[i] = i * fac[i-1]) %= M;

    inv[MAX-1] = power(fac[MAX-1], M-2);
    for (int i = MAX-2; i >= 0; i--) (inv[i] = (i+1) * inv[i+1]) %= M;
}

ll ncr(int a, int b) {
    return (fac[a] * inv[b] % M * inv[a-b] % M) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    ll res = 0;
    precompute();

    // i represents how many a's there are. n-i = # of b's.
    for (int i = 0; i <= n; i++) {
        int sum = a * i + b * (n-i);
        // if sum is good, then add n choose i bc n spots, choosing i spots for where the a's go.
        if (check_excel(sum, a, b)) (res += ncr(n, i)) %= M;
    }

    cout << res << "\n";
}