#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> cubes;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;

        cubes.push_back({k, i});
    }

    sort(cubes.begin(), cubes.end());

    ll numTowers = 1;

    for (int i = 1; i < n; i++) {
        int cubeTop = cubes[i-1].second, cubeUnder = cubes[i].second;

        if (cubeUnder > cubeTop) numTowers++;
    }

    cout << numTowers << "\n";
}