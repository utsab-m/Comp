#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;

const ld PI = acosl(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("angle2.in", "r", stdin);
    freopen("angle2.out", "w", stdout);

    cout << fixed << setprecision(5);

    ld x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    ld a1 = atan2l(y1, x1);
    ld a2 = atan2l(y2, x2);

    ld diff = fabsl(a1 - a2);

    if (diff > PI) {
        diff = 2 * PI - diff;
    }

    cout << diff << '\n';
}