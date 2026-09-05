#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll dfs(int u, int t, ll pushed) {
    if (pushed == 0) return 0;
    if (u == t) return pushed;

    for (int& cid = ptr[u]; cid < (int)adj[u].size(); ++cid) {
        auto& edge = adj[u][cid];
        int tr = edge.to;

        if (edge.cap - edge.flow > 0 && level[tr] = level[u] + 1) {
            ll push = dfs(tr, t, min(pushed, edge.cap - edge.flow));

            if (push == 0) continue;

            edge.flow += push;
            adj[tr][edge.rev] -= push;
            return push;
        }
    }

    return 0;
}

ll max_flow(int s, int t) {
    ll flow = 0;
    const ll INF = 1e18;

    while (bfs(s, t)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (ll pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
}