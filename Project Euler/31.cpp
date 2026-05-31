#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll dp[201][9];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> coins({1, 2, 5, 10, 20, 50, 100, 200});
    dp[0][0] = 1;

    for (int i = 0; i <= 200; i++) {
        for (int j = 1; j <= 8; j++) {
            // dp[i][j] = ways to make currency i with subset of coins [0],1,2,...,i
            // choices: choose coin i in the subset or don't. both are valid.
            // choose it (if possible)
            if (i - coins[j-1] >= 0) dp[i][j] += dp[i-coins[j-1]][j];

            // don't choose it
            dp[i][j] += dp[i][j-1];
        }
    }

    cout << dp[200][8] << "\n";
}