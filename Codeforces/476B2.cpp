#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int dp[11][11];

double ncr(int n, int r) {
    if (n < 0 || r < 0 || n < r) return 0;
    return dp[n][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == j || j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }    
    }

    int plusOne = 0, minusOne = 0, plusTwo = 0, minusTwo = 0, blank = 0;

    for (char c: s1) {
        if (c == '+') plusOne++;
        else minusOne++;
    }

    for (char c: s2) {
        if (c == '+') plusTwo++;
        else if (c == '-') minusTwo++;
        else blank++;
    }

    cout << ncr(blank, plusOne - plusTwo) * ncr(blank - plusOne, minusOne - minusTwo) / (1 << blank) << '\n';
}