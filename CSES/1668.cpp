#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

bool dfs(vector<vector<int>>& adj, vector<int>& groups, int curr, int color) {
    groups[curr] = color; // 1 = red, 2 = blue

    for (int neighbor: adj[curr]) {
        if (groups[neighbor] == 0) {
            // unvisited, pass 1 if 2, pass 2 if 1
            if (!dfs(adj, groups, neighbor, 3-color)) {
                return false;
            }
        } else if (groups[neighbor] == color) {
            // neighbor on same team
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool isPossible = true;
    vector<int> groups(n+1);

    for (int i=1; i<=n; ++i) {
        if (!groups[i]) {
            if (!dfs(adj, groups, i, 1)) {
                isPossible = false;
                break;
            }
        }
    }

    if (isPossible) {
        for (int i=1; i<=n; ++i) {
            cout << groups[i] << ' ';
        }
    } else {
        cout << "IMPOSSIBLE";
    }
    
    cout << '\n';
}