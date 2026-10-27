#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}

    ll cross(const Point& o) const {
        return x * o.y - y * o.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Point> points(n);
    for (int i=0; i<n; ++i) {
        int x, y; cin >> x >> y;
        points[i] = Point(x, y);
    }
    
    ll ans = 0;
    for (int i=0; i<n; ++i) {
        Point left = points[i], right = points[(i+1) % n];
        ans += left.cross(right);
    }

    cout << abs(ans) << '\n';
}