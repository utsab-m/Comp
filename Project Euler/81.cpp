#include "bits/stdc++.h"
#include <fstream>
#include <sstream>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("81.txt");

    int n = 80;
    const int INF = 1e9;
    vector<vector<int>> dp(n+1, vector<int>(n+1, INF));
    dp[0][1] = 0;

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(file, line);
        stringstream ss(line);
        for (int j = 1; j <= n; ++j) {
            // 2 choices: go right or go down
            // dp(i, j) represents minimal path sum from (1,1) to (i,j)
            // so just get minimum of sum of up and left and add the curr val to it
            string num;
            getline(ss, num, ',');
            dp[i][j] = stoi(num) + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[80][80] << '\n';
}