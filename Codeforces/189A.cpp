#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> lengths(3);
    cin >> n >> lengths[0] >> lengths[1] >> lengths[2];

    sort(lengths.begin(), lengths.end());

    vector<vector<int>> dp(n+1, vector<int>(4));

    for (int j = 1; j <= 3; j++) {
        int length = lengths[j-1];
        for (int i = 1; i <= n; i++) {
            if (length <= i) {
                dp[i][j] = max(1 + dp[i-length][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][3] << "\n";
}