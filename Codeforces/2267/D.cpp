#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;

    vector<int> a(n+5), pos(n+5);

    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        pos[a[i]] = i%2;
    }

    int balance = 0;

    for (int x=n; x>0; x--) {
        if (pos[x] % 2 == 0) ++balance;
        else --balance;

        if (abs(balance) > 1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}