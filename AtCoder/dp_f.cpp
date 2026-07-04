#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int m = s.size(), n = t.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }

    string res;
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            res += s[i-1];
            i--;
            j--;
        } else if (dp[i-1][j] >= dp[i][j-1]) {
            i--;
        } else j--;
    }

    reverse(res.begin(), res.end());

    cout << res << '\n';
}