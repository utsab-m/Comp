#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAXN = 2e5+5;
vector<int> adj[MAXN];

// dp[a][0]: max matching in subtree a, a is NOT paired
// dp[a][1]: max matching in subtree a, a is paired with a child
int dp[MAXN][2];

void dfs(int a, int p) {
    // first, solve the subproblems for all children
    for (int v: adj[a]) {
        if (v != p) {
            dfs(v, a);
            // scenario a: a is NOT paired, so we just take the best outcome from child v
            dp[a][0] += max(dp[v][0], dp[v][1]);
        }
    }

    // scenario b: a is paired. test pairing a with each child to find the max outcome
    for (int v: adj[a]) {
        if (v != p) {
            // swap-out logic: start with the total score if a was unpaired
            // subtract the score child v contributed to the total
            // add the score where v is forced to be unpaired (dp[v][0]) plus 1 for the new edge
            int candidate = dp[a][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1;
            dp[a][1] = max(dp[a][1], candidate);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // arbitrarily the root is 1
    dfs(1, 0);

    // answer = best outcome at root node
    cout << max(dp[1][0], dp[1][1]) << '\n';
}