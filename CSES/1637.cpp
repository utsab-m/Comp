#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n+1);

    for (int i = 1; i <= n; i++) {
        int y = i;
        int mx = 0;
        while (y != 0) {
            mx = max(mx, y % 10);
            y /= 10;
        }
        dp[i] = 1 + dp[i - mx];
    }

    cout << dp[n] << "\n";
}