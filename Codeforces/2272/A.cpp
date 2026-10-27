#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& x: a) cin >> x;

    if (k == 1) {
        cout << -1 << '\n';
    } else {
        bool changed = false;
        int ansI, ansJ;

        vector<int> f(n);
        f[n-1] = n;
        for (int l=n-2; l>=0; --l) f[l] = min(a[l+1], f[l+1]);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<n; ++i) {
            pq.push(f[i]);
            if (pq.size() > k) pq.pop();
        }
        int maxK = pq.top();

        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                swap(a[i], a[j]);
                f[n-1] = n;
                for (int l=n-2; l>=0; --l) f[l] = min(a[l+1], f[l+1]);
                priority_queue<int, vector<int>, greater<int>> pq;
                for (int i=0; i<n; ++i) {
                    pq.push(f[i]);
                    if (pq.size() > k) pq.pop();
                }
                if (pq.top() > maxK) {
                    changed = true;
                    maxK = pq.top();
                    ansI = i+1;
                    ansJ = j+1;
                }
                swap(a[i], a[j]);
            }
        }

        if (!changed) cout << -1 << '\n';
        else cout << ansI << ' ' << ansJ << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}