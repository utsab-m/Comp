#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> dp(x+1), coins(n);
    dp[0] = 1;

    for (auto &c: coins) cin >> c;

    for (int i = 1; i <= x; i++) {
        for (int c: coins) {
            if (i - c >= 0) (dp[i] += dp[i-c]) %= MOD;
        }
    }

    cout << dp[x] % MOD << "\n";
}