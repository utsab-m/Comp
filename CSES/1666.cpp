#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void dfs(vector<vector<int>>& adj, vector<bool>& vis, int n, int p) {
    vis[n] = true;
    for (int c: adj[n]) {
        if (c != p && !vis[c]) {
            dfs(adj, vis, c, n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> groups;
    vector<bool> vis(n+1);

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            groups.push_back(i);
            dfs(adj, vis, i, 0);
        }
    }

    cout << groups.size()-1 << '\n';
    for (int i = 0; i < groups.size()-1; ++i) {
        cout << groups[i] << ' ' << groups[i+1] << '\n';
    }
}