#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<int> coins;
int INF = 1e9;

int solve(vector<int>& dp, vector<bool>& ready, int x) {
    if (x < 0) return INF;
    else if (x == 0) return dp[0];

    if (ready[x]) return dp[x];
    
    int best = INF;

    for (auto c: coins) {
        best = min(best, solve(dp, ready, x - c) + 1);
    }

    dp[x] = best;
    ready[x] = true;
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }

    vector<int> dp(x+1);
    vector<bool> ready(x+1, false);
    int res = solve(dp, ready, x);
    res = (res == INF) ? -1 : res;
    
    cout << res << "\n";
    
}