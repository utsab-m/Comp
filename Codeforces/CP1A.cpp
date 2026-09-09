#include "bits/stdc++.h"
using namespace std;
using ll = long long;

long double PI = acosl(-1);

long double get_polar(ll x, ll y) {
    long double alpha = atan2l(y, x);
    return alpha < 0 ? alpha + 2 * PI : alpha;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("angle1.in", "r", stdin);
    freopen("angle1.out", "w", stdout);

    ll x, y; cin >> x >> y;
    cout << fixed << setprecision(9) << get_polar(x, y) << '\n';

    
}