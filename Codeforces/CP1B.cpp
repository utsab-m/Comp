#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;

ld magnitude(ld x, ld y) {
    return sqrt(x * x + y * y);
}

ld dot_product(ld x1, ld y1, ld x2, ld y2) {
    return x1 * x2 + y1 * y2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("angle2.in", "r", stdin);
    // freopen("angle2.out", "w", stdout);

    cout << fixed << setprecision(5);

    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    cout << acos(dot_product(x1, y1, x2, y2) / (magnitude(x1, y1) * magnitude(x2, y2))) << '\n';
}