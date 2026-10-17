#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9+7;

bool between(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) {
    return min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2);
}

ld get_m(ld x1, ld y1, ld x2, ld y2) {
    if (y1 == y2) return -INFINITY;
    return (y2-y1)/(x2-x1);
}

// ld x1, ld y1, ld x2, ld y2, ld x3, ld y3, ld x4, ld y4

void solve() {
    ld x1, y1, x2, y2, x3, y3, x4, y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    ld m1 = get_m(x1, y1, x2, y2), m2 = get_m(x3, y3, x4, y4);
    if (m1 == -INFINITY && m2 == -INFINITY) {
        if (y1 == y3) {
            if (between(x1, y1, x2, y2, x3, y3) || between(x1, y1, x2, y2, x4, y4)) {
                cout << "YES" << '\n';
                return;
            }
        }
        cout << "NO" << '\n';
        return;
    }

    ld b1 = y2 - m1 * x2, b2 = y4 - m2 * x4;

    if (m1 == -INFINITY && m2 != -INFINITY) {
        ld y = y1, x = (y-b2)/m2;
        if (between(x1, y1, x2, y2, x, y) && between(x3, y3, x4, y4, x, y)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        return;
    } else if (m2 == -INFINITY && m1 == -INFINITY) {
        ld y = y2, x = (y-b1)/m1;
        if (between(x1, y1, x2, y2, x, y) && between(x3, y3, x4, y4, x, y)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        return;
    }

    if (m1 == m2) {
        if (b1 == b2) {
            if (between(x1, y1, x2, y2, x3, y3) || between(x1, y1, x2, y2, x4, y4)) {
                cout << "YES" << '\n';
                return;
            }
        }
        cout << "NO" << '\n';
        return;
    }

    // possible to have an intersecting point
    ld x = (b2-b1)/(m1-m2), y = m1 * x + b1;
    // check if the point is in range
    if (between(x1, y1, x2, y2, x, y) && between(x3, y3, x4, y4, x, y)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}