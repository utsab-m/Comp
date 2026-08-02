#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

struct SegTree {
    int n;
    vector<ll> tree;

    SegTree(const vector<ll>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n-1);
    }

    void build(const vector<ll>& arr, int node, int L, int R) {
        if (L == R) {
            tree[node] = arr[L];
            return;
        }
        int M = L + (R-L) / 2;
        build(arr, 2 * node, L, M);
        build(arr, 2 * node + 1, M+1, R);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int node, int L, int R, int idx, ll val) {
        if (L == R) {
            tree[node] = val;
            return;
        }
        int M = L + (R-L) / 2;
        if (idx <= M) {
            update(2 * node, L, M, idx, val);
        } else {
            update(2 * node + 1, M+1, R, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    ll query(int node, int L, int R, int qL, int qR) {
        if (qL <= L && R <= qR) return tree[node];
        if (qR < L || qL > R) return 0;

        int M = L + (R-L) / 2;
        return query(2 * node, L, M, qL, qR) + query(2 * node + 1, M+1, R, qL, qR);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }

    ll query(int qL, int qR) {
        return query(1, 0, n-1, qL, qR);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for (ll& num: arr) cin >> num;

    SegTree st(arr);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
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