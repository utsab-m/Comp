#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> rank, parent, first_speaker;
    int count;
    
    UnionFind(int n, int m) : count(n) {
        rank.assign(n+1, 0);
        first_speaker.assign(m+1, 0);
        parent.resize(n+1);
        for (int i=1; i<=n; ++i) parent[i] = i;
    }

    int find(int i) {
        return parent[i] == i ? i : find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_j] > rank[root_i]) swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_j] == rank[root_i]) ++rank[root_i];
            --count;
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    UnionFind dsu(n, m);
    bool all_zero = true;

    for (int i=1; i<=n; ++i) {
        int k;
        cin >> k;

        if (k > 0) all_zero = false;

        for (int j=0; j<k; ++j) {
            int lang;
            cin >> lang;

            if (dsu.first_speaker[i] == 0) dsu.first_speaker[i] = i;
            else dsu.unite(i, dsu.first_speaker[lang]);
        }
    }

    if (all_zero) cout << n << '\n';
    else cout << dsu.count-1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}