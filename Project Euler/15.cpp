#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxRow = 40, maxCol = 20;
    vector<vector<ull>> dp(maxRow+1, vector<ull>(maxRow+1));

    for (int i = 0; i <= maxRow; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] = 1;
            else if (i == j) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    cout << dp[40][20] << "\n";
}