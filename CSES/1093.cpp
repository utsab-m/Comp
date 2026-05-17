#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int dp[501][500 * 501 / 2 + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = (n * (n+1)) / 2;

    dp[0][0] = 1;

    if (sum % 2 == 1) {
        cout << 0 << "\n";
    } else {
        for (int i = 1; i <= n; i++) {
            // if sum is odd, it's 0
            int s = i * (i+1) / 2;
            
            for (int j = 1; j <= s; j++) {
                // choose i
                if (j-i >= 0) (dp[i][j] += dp[i-1][j-i]) %= MOD; 
                // don't choose i
                (dp[i][j] += dp[i-1][j]) %= MOD;
            }
            
        }

        cout << dp[n][sum / 2] << "\n";
    }
    
}