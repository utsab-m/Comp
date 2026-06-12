#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int res = 0;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            res = max(res, a);
        }

        cout << res << "\n";
    }
}