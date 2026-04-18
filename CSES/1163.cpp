#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    set<int> lights{0, x};
    multiset<int> gaps{x};

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        auto pr = lights.upper_bound(p);
        auto pl = pr;
        int dr = *pr - p;
        --pl;
        int dl = p - *pl;
        int d = dl + dr;

        gaps.erase(gaps.find(d));
        gaps.insert(dl);
        gaps.insert(dr);

        lights.insert(p);

        cout << *gaps.rbegin() << "\n";
    }
}