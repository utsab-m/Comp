#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n-1);
    }

    void build(const vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }

        int m = l + (r-l) / 2;
        build(arr, 2 * node, l, m);
        build(arr, 2 * node + 1, m+1, r);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int m = l + (r-l) / 2;
        if (idx <= m) {
            update(2 * node, l, m, idx, val);
        } else {
            update(2 * node + 1, m+1, r, idx, val);
        }

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    ll query(int node, int l, int r, int a, int b) {
        if (a <= l && r <= b) return tree[node];
        if (l > b || r < a) return INT_MAX;

        int m = l + (r-l)/2;
        return min(query(2 * node, l, m, a, b), query(2 * node + 1, m+1, r, a, b));
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }

    ll query(int a, int b) {
        return query(1, 0, n-1, a, b);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int& num: arr) cin >> num;

    SegTree st(arr);

    while (q--) {
        int num;
        cin >> num;

        if (num == 1) {
            int k, u;
            cin >> k >> u;
            st.update(k-1, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << st.query(a-1, b-1) << '\n';
        }
    }
}