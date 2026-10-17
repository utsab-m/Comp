#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> balloonCount;
    map<int, set<int>> problemsSolved;

    int n; cin >> n;

    for (int i=0; i<n; ++i) {
        int a, b, c; cin >> a >> b >> c;

        // if team hasn't solved yet, potential points
        if (problemsSolved[a].find(b) != problemsSolved[a].end()) {
            cout << 0 << '\n';
        } else {
            if (c < 240 || balloonCount[a] < 3) {
                cout << b << '\n';
                ++balloonCount[a];
            } else {
                cout << 0 << '\n';
            }
            problemsSolved[a].insert(b);
            continue;
        }
    }
}