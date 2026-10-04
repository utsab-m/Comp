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

        vector<int> count(3);

        for (int i=0; i<n; ++i) {
            int a;
            cin >> a;

            a <= 1 ? ++count[a] : ++count[2];
        }

        if (count[0] <= (n+1)/2) cout << 0 << '\n';
        else if (count[1] == 0 || count[2] != 0) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}