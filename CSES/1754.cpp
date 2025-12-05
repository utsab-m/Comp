#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    for (int i=1; i<=t; i++) {
        ll l, r;
        cin >> l;
        cin >> r;

        if (((l+r) % 3 != 0) || (l < r && l * 2 < r) || (r < l && r * 2 < l)) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}