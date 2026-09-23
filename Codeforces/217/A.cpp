#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAX = 1000;

void dfs(vector<vector<int>>& adj, vector<int>& vis, int n, int p) {
    vis[n] = true;
    for (int c: adj[n]) {
        if (!vis[c]) {
            dfs(adj, vis, c, n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n), y(n);
    vector<vector<int>> adj(n);
    vector<int> vis(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (x[i] == x[j] || y[i] == y[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int groups = 0;

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ++groups;
            dfs(adj, vis, i, -1);
        }
    }

    cout << groups-1 << '\n';
}