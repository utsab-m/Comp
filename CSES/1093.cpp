#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

const int maxN = 500, maxSum = maxN * (maxN+1) / 4;
ll dp[maxSum+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = n * (n+1) / 2;
    if (sum % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        for (int s = sum / 2; s - i >= 0; --s) {
            (dp[s] += dp[s-i]) %= MOD;
        }
    }

    cout << dp[sum / 2] << '\n';
}