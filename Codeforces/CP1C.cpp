#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll signed_cross(ll x1, ll y1, ll x2, ll x2) {
    return x1 * y2 - x2 * y1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<ll, ll>>> points(n);
    for (auto &[x, y]: points) cin >> x >> y;

    ll total_area = 0;
    for (int i = 0; i < n; ++i) {
        auto &[x1, y1] = points[i];
        auto &[x2, y2] = points[(i+1)%n]

        total_area += signed_cross(x1, y1, y2,)
    }
}