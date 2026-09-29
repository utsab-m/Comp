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
    vector<int> indegree(n+1);

    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ++indegree[b];
    }

    queue<int> q;

    for (int i=1; i<=n; ++i) {
        if (!indegree[i]) q.push(i);
    }

    vector<int> order;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        order.push_back(curr);

        for (int next: adj[curr]) {
            --indegree[next];
            if (!indegree[next]) q.push(next);
        }
    }

    if ((int)order.size() < n) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        for (int course: order) cout << course << " ";
    }
    cout << '\n';
}