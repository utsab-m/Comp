#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    bool possible = false;

    map<int, int> indices;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        int rest = x - a;

        if (indices[rest] > 0) {
            possible = true;
            cout << i << " " << indices[rest] << "\n";
            break;
        }
        indices[a] = i;
    }

    if (!possible) {
        cout << "IMPOSSIBLE" << "\n";
    }
}