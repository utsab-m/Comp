#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto get_distances = [&](int node) -> vector<int> {
        vector<int> distances(n+1, -1);
        distances[node] = 0;
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v: adj[u]) {
                if (distances[v] == -1) {
                    distances[v] = distances[u] + 1;
                    q.push(v);
                }
            }
        }

        return distances;
    };

    int A = 1;
    vector<int> dist1 = get_distances(1);
    for (int i = 1; i <= n; ++i) if (dist1[i] > dist1[A]) A = i;

    int res = 0;
    vector<int> distA = get_distances(A);
    for (int i = 1; i <= n; ++i) res = max(res, distA[i]);

    cout << res << '\n';
}