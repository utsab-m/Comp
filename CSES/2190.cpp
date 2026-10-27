#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

struct Point {
    ll x, y;

    Point operator-(const Point& o) const {
        return {x-o.x, y-o.y};
    }

    ll cross(const Point& o) const {
        return x * o.y - y * o.x;
    }

    ll cross(const Point& a, const Point& b) {
        return (a - *this).cross(b - *this);
    }
};

bool onSegment(Point p, Point a, Point b) {
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
        && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

int sign(ll num) {
    if (num < 0) return -1;
    else if (num == 0) return 0;
    else return 1;
}

void solve() {
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    int cp1 = sign(p1.cross(p2, p3));
    int cp2 = sign(p1.cross(p2, p4));
    int cp3 = sign(p3.cross(p4, p1));
    int cp4 = sign(p3.cross(p4, p2));

    if (cp1 != cp2 && cp3 != cp4) {
        cout << "YES\n";
        return;
    }

    if (cp1 == 0 && onSegment(p3, p1, p2)) {
        cout << "YES\n";
        return;
    }
    if (cp2 == 0 && onSegment(p4, p1, p2)) {
        cout << "YES\n";
        return;
    }
    if (cp3 == 0 && onSegment(p1, p3, p4)) {
        cout << "YES\n";
        return;
    }
    if (cp4 == 0 && onSegment(p2, p3, p4)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}