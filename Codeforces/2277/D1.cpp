#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ull MOD = 998244353;

void solve() {
    ull l, r; cin >> l >> r;

    ull ans = 0;

    for (ull i=l; i<=r; ++i) {
        // int num1 = (int)log2(i) + 1;
        // // cout << num1 << '\n';
        // ull power = (ull)pow(2, num1) - 1;
        // // cout << power << '\n';
        // ull num0 = (power - i) % MOD;
        // ans = (ans + num1 + num0) % MOD;
        ull num = i, k = 1, missing = 0, numDigits = 0;
        while (num > 0) {
            if (num % 2 == 0) {
                missing += k;
            }
            num /= 2;
            k *= 2;
            ++numDigits;
        }
        (ans += numDigits + missing % MOD) %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}