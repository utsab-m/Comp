#include "bits/stdc++.h"
#include <array>
using namespace std;
using ll = long long;

const int MOD = 1e9+7, MAX = 1e5+1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<array<int, 2>> ranges(n);
        for (int i = 0; i < n; ++i) cin >> ranges[i][0] >> ranges[i][1];

        vector<vector<int>> children(n);
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;

            --u; --v;
            children[u].push_back(v);
            children[v].push_back(u);
        }

        vector<array<ll, 2>> dp(n, {0, 0});

        auto dfs = [&](auto& self, int u, int p) -> void {
            for (int c: children[u]) {
                if (c == p) continue;
                self(self, c, u);
                dp[u][0] += max(abs(ranges[u][0] - ranges[c][0]) + dp[c][0], abs(ranges[u][0] - ranges[c][1]) + dp[c][1]);
                dp[u][1] += max(abs(ranges[u][1] - ranges[c][0]) + dp[c][0], abs(ranges[u][1] - ranges[c][1]) + dp[c][1]);
            }
        };

        dfs(dfs, 0, -1);
        cout << max(dp[0][0], dp[0][1]) << '\n';
    }
}