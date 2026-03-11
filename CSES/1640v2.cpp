#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> indices;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        indices.push_back({a, i});
    }

    sort(indices.begin(), indices.end());

    int i = 0, j = n-1;

    while (i < j) {
        ll sum = indices[i].first + indices[j].first;

        if (sum == x) {
            cout << indices[i].second << " " << indices[j].second << "\n";
            return 0;
        } else if (sum > x) {
            j--;
        } else {
            i++;
        }
    }

    cout << "IMPOSSIBLE" << "\n";
}