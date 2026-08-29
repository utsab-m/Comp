#include "bits/stdc++.h"
#include <array>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int N = 2e5+1;
vector<int> g[N];

array<int, 2> dfs(int node, int parent) {
    auto dp = array{0, 0};

    for (int child: g[node]) {
        if (child == parent) continue;

        auto child_dp = dfs(child, node);
        dp[1] = max({dp[0] + child_dp[0] + 1, dp[1] + child_dp[1], dp[1] + child_dp[0]});
        dp[0] += max(child_dp[0], child_dp[1]);
    }

    return dp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto res = dfs(1, 1);
    cout << max(res[0], res[1]) << '\n';
}