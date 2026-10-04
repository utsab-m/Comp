#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct UnionFind {
    int n;
    vector<int> rank, parent, size;

    UnionFind(int n) {
        rank.assign(n, 0);
        size.assign(n, 1);
        parent.resize(n);
        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }
    }

    int getLeader(int a) {
        return parent[a] == a ? a : getLeader(parent[a]);
    }

    void merge(int a, int b) {
        a = getLeader(a); b = getLeader(b);
        if (a == b) return;

        if (rank[a] == rank[b]) ++rank[a];

        if (rank[a] > rank[b]) {
            parent[b] = a;
            size[a] += size[b];
        } else {
            parent[a] = b;
            size[b] += size[a];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    UnionFind d(n);

    int cnt=n, maxi=1;

    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        if (d.getLeader(a) != d.getLeader(b)) {
            --cnt;
        }

        d.merge(a, b);
        int leader = d.getLeader(a);
        maxi = max(maxi, d.size[leader]);

        cout << cnt << " " << maxi << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}