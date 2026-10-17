#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

long double cross_product(double x1, double y1, double x2, double y2, double x3, double y3) {
    long double u_x = x2-x1, u_y=y2-y1, v_x=x3-x1, v_y=y3-y1;

    return u_x * v_y - u_y * v_x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        long double cross = cross_product(x1, y1, x2, y2, x3, y3);

        if (cross == 0) {
            cout << "TOUCH" << '\n';
        } else if (cross > 0) {
            cout << "LEFT" << '\n';
        } else {
            cout << "RIGHT" << '\n';
        }
    }
}