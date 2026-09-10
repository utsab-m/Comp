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
        ll x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        ll ax = x2 - x1, ay = y2 - y1;
        ll bx = x3 - x1, by = y3 - y1;

        ll cross = ax * by - ay * bx;

        if (cross < 0) {
            cout << "RIGHT" << '\n';
        } else if (cross > 0) {
            cout << "LEFT" << '\n';
        } else {
            cout << "TOUCH" << '\n';
        }
    }
}