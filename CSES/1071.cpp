#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        ll x, y;
        cin >> y;
        cin >> x;

        ll j = max(x, y);
        ll res = (j * j) - j + 1;

        if (x == y) {
            cout << res << "\n";
        } else {
            ll add;
            if (x < j) {
                add = j - x;
                if (j % 2 != 0) add *= -1;
            } else {
                add = j - y;
                if (j % 2 == 0) add *= -1;
            }
            res += add;
            cout << res << "\n";
        }
        
    }
}