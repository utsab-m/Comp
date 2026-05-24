#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> heights(n), dp(n, INT_MAX);
    dp[0] = 0;
    for (int& height: heights) cin >> height;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i-j] + abs(heights[i] - heights[i-j]));
            } else break;
        }
    }

    cout << dp[n-1] << "\n";
}