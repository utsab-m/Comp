#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n;
    cin >> n;

    set<int> quotients;

    for (int i=0; i<n; ++i) {
        int p;
        cin >> p;

        quotients.insert((p-1) / 10);
    }

    cout << quotients.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}