#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MAX = 100;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<ll>> dp(MAX+1, vector<ll>(MAX+1));

    ll count = 0;
    
    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            if (dp[i][j] > 1000000 || dp[i][j] < 0) count++;
        }
    }

    cout << count << "\n";
}