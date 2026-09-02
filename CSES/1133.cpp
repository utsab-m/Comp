#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAX = 2e5+1;
ll res[MAX+1];
int subSize[MAX+1];
ll subDist[MAX+1];
vector<int> adj[MAX+1];
int n;

void dfs1(int node, int parent) {
    subSize[node] = 1;

    for (int child: adj[node]) {
        if (child != parent) {
            dfs1(child, node);

            subSize[node] += subSize[child];
            subDist[node] += subDist[child] + subSize[child];
        }
    }
} 

void dfs(int node, int parent) {
    res[node] = res[parent] + (n - subSize[node]) - subSize[node];

    for (int child: adj[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> n;

    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, -1);
    res[1] = subDist[1];

    for (int child: adj[1]) {
        dfs(child, 1);
    }

    for (int i = 1; i <= n; ++i) {
        cout << res[i] << '\n';
    }
}