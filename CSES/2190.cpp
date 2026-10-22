#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int sign(ll x) {
    if (x == 0) return 0;
    else if (x < 0) return -1;
    else return 1;
}

ll cross_product(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll vx=x2-x1, vy=y2-y1, ux=x3-x2, uy=y3-y2;
    return vx * uy - vy * ux;
}

bool between(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2);
}

void solve() {
    ll x1, y1, x2, y2, x3, y3, x4, y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int cross3 = sign(cross_product(x1, y1, x2, y2, x3, y3)), cross4 = sign(cross_product(x1, y1, x2, y2, x4, y4));
    bool between3 = between(x1, y1, x2, y3, x3, y3), between4 = between(x1, y1, x2, y3, x4, y4);
    if ((between3 && cross3 == 0) || (between4 && cross4 == 0) || cross3 != cross4) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}