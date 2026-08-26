#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const ll INF = 1e18;

struct Edge {
    int to;
    ll cap;
    ll flow;
    int rev;
};

const int MAXN = 505;
vector<Edge> adj[MAXN];
int level[MAXN];
int ptr[MAXN];

// add directed edge with forward capacity 'cap' and 0 reverse capacity
void add_edge(int from, int to, ll cap) {
    adj[from].push_back({to, cap, 0, (int)adj[to].size()});
    adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
}

// BFS to construct the level graph
bool bfs(int s, int t) {
    fill(level, level + MAXN, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto& edge: adj[v]) {
            // Traverse edgse that have remaining capacity and are unvisited
            if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }

    return level[t] != -1;
}

ll dfs(int v, int t, ll pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;

    for (int& cid = ptr[v]; cid < adj[v].size(); ++cid) {
        auto& edge = adj[v][cid];
        int trg = edge.to;

        // DFS only moves strictly one level forward
        if (level[v] + 1 != level[trg] || edge.cap - edge.flow == 0) continue;

        ll tr = dfs(trg, t, min(pushed, edge.cap - edge.flow));
        if (tr == 0) continue;

        // Update residual capacities
        edge.flow += tr;
        adj[trg][edge.rev].flow -= tr;
        return tr;
    }

    return 0;
}

ll dinic(int s, int t) {
    ll flow = 0;
    while (bfs(s, t)) {
        fill(ptr, ptr + MAXN, 0);
        while (ll pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        add_edge(u, v, c);
    }

    cout << dinic(1, n) << '\n';

    return 0;
}