#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 80;
    vector<vector<int>> grid(N+1, vector<int>(N+1, MOD));
    vector<vector<int>> dp(N+1, vector<int>(N+1));

    ifstream file("81.txt");    

    for (int i = 1; i <= N; ++i) {
        string line;
        getline(file, line);
        stringstream ss(line);
        for (int j = 1; j <= N; ++j) {
            string s;
            getline(ss, s, ',');
            grid[i][j] = stoi(s);
        }
    }

    for (int i = 1; i <= N; ++i) dp[i][1] = grid[i][1];

    

    for (int j = 2; j <= N; ++j) {
        for (int i = 1; i <= N; ++i) {
            dp[i][j] = dp[i][j-1] + grid[i][j];
        }

        for (int i = 2; i <= N; ++i) {
            dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
        }

        for (int i = N-1; i >= 1; --i) {
            dp[i][j] = min(dp[i][j], dp[i+1][j] + grid[i][j]);
        }
    }
    int res = INT_MAX;
    for (int i = 2; i <= N; ++i) res = min(res, dp[i][N]);
    cout << res << '\n';

}