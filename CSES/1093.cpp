#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAX = 500 * 501 / 4;
ll dp[MAX+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    dp[0] = 1;

    int sum = n * (n+1) / 2;
    if (sum % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }
    int half = sum / 2;

    for (int x = 1; x < n; ++x) {
        for (int s = half; s - x >= 0; --s) {
            (dp[s] += dp[s-x]) %= MOD;
        }
    }
    
    cout << dp[half] << '\n';
}