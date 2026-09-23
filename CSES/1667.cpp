#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    vector<int> vis(n+1), parent(n+1);
    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor: adj[curr]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;

                parent[neighbor] = curr;

                q.push(neighbor);
            }
        }
    }

    if (parent[n] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;
    int step = n;

    while (step != 0) {
        path.push_back(step);
        step = parent[step];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';

    for (int city: path) cout << city << ' ';
    cout << '\n';
}