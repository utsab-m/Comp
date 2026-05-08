#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    vector<int> a(n), b(m);

    for (int& a_i: a) cin >> a_i;
    for (int& b_j: b) cin >> b_j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    vector<int> res;

    function<void(int, int)> printLCS = [&](int i, int j) {
        if (i == 0 || j == 0) return;
        if (a[i-1] == b[j-1]) {
            printLCS(i-1, j-1);
            cout << a[i-1] << " ";
        } else if (dp[i-1][j] > dp[i][j-1]) {
            printLCS(i-1, j);
        } else {
            printLCS(i, j-1);
        }
    };

    cout << dp[n][m] << "\n";

    printLCS(n, m);
}