#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

pair<int, int> slope(int x1, int y1, int x2, int y2) {
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    } else if (x1 == x2 && y1 > y2) {
        swap(y1, y2);
    }

    return {y2-y1, x2-x1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    map<pair<int, int>, int> count;
    vector<pair<int, int>> points(n);

    ll c = 0;
    
    for (int i=0; i<n; ++i) {
        int x, y; cin >> x >> y;
        points[i] = {x, y};
        
        for (int j=0; j<i; ++j) {
            auto point = points[j];
            auto m = slope(x, y, point.first, point.second);
            ++count[m];
        }

        
    }

    cout << c << '\n';
}