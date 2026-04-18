#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> towers;

    // for (int i = 0; i < n; i++) {
    //     int k;
    //     cin >> k;

    //     if (towers.empty()) towers.push_back(k);
    //     else {
    //         int l = 0, r = towers.size();

    //         bool place = false;
            
    //         while (l < r) {
    //             int m = l + (r - l) / 2;

    //             if (towers[m] <= k) {
    //                 l = m + 1;
    //             } else {
    //                 r = m;
    //                 place = true;
    //             }
    //         }

    //         if (place) {
    //             towers[r] = k;
    //         } else {
    //             towers.push_back(k);
    //         }
    //     }
    // }

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        auto it = upper_bound(towers.begin(), towers.end(), k);

        if (it == towers.end()) {
            towers.push_back(k);
        } else {
            *it = k;
        }
    }

    cout << towers.size() << "\n";
}