#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> dp(x+1), coins(n);
    dp[0] = 1;

    for (int& c: coins) cin >> c;

    for (int c = 0; c < n; c++) {
        for (int i = 0; i <= x; i++) {
            if (i - coins[c] >= 0) (dp[i] += dp[i-coins[c]]) %= M;
        }
    }

    cout << dp[x] << "\n";
}