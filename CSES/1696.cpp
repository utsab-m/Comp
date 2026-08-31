#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

struct Edge {
    int to;
    ll cap, flow;
    int rev;
};

vector<Edge> edges;
vector<vector<int>> adj;

void addEdge(int from, int to, ll cap) {
    adj[from].push_back(edges.size());
    edges.push_back({to, cap, 0, (int)edges.size() + 1});
    adj[to].push_back(edges.size());
    edges.push_back({from, 0, 0, (int)edges.size() - 1});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    int source = 0, sink = n+m+1;
    adj.resize(n+m+2);

    for (int i = 1; i <= n; ++i) addEdge(source, i, 1);
    for (int i = 1; i <= m; ++i) addEdge(n+i, sink, 1);
    for (int i = 0; i < k; ++i) {
        int b, g;
        cin >> b >> g;
        addEdge(b, n+g, 1);
    }

    vector<int> level(n+m+2);

    auto bfs = [&]() -> bool {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;

        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i: adj[u]) {
                Edge& e = edges[i];

                if (level[e.to] == -1 && e.cap - e.flow > 0) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }

        return level[sink] != -1;
    };

    vector<int> ptr(n+m+2);

    auto dfs = [&](auto& self, int u, ll pushed) -> ll {
        
    };
}