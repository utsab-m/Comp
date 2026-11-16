#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    int l=0, r=n-1;

    int minA = 1, maxA = n;

    while (l <= r) {
        bool moved = false;
        if (a[l] == maxA) {
            --maxA;
            ++l;
            moved = true;
        } else if (a[l] == minA) {
            ++minA;
            ++l;
            moved = true;
        }
        if (a[r] == maxA) {
            --maxA;
            --r;
            moved = true;
        } else if (a[r] == minA) {
            ++minA;
            --r;
            moved = true;
        }
        if (!moved) break;
    }

    if (l <= r) {
        cout << l+1 << ' ' << r+1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}