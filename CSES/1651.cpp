#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

struct FenTree {
    vector<ll> bit;
    int n;

    FenTree(int n) {
        this->n = n+2;
        bit.resize(this->n);
    }

    FenTree(vector<ll>& arr) : FenTree(arr.size()) {
        for (int i = 0; i < (int)arr.size(); ++i) {
            ll diff = arr[i] - (i > 0 ? arr[i-1] : 0);
            add(i+1, diff);
        }
    }

    void add(int idx, ll val) {
        for (; idx < n; idx += idx & -idx) bit[idx] += val;
    }

    void range_add(int l, int r, ll val) {
        add(l, val);
        add(r+1, -val);
    }

    ll point_query(int idx) {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for (ll& num: arr) cin >> num;

    FenTree ft(arr);

    while (q--) {
        int num;
        cin >> num;

        if (num == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            ft.range_add(a, b, u);
        } else {
            int k;
            cin >> k;
            cout << ft.point_query(k) << '\n';
        }
    }
}