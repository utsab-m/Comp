#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> res;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (res.empty()) {
            res.push_back(x);
        } else {
            auto it = lower_bound(res.begin(), res.end(), x);

            if (it == res.end()) {
                res.push_back(x);
            } else {
                *it = x;
            }
        }
    }

    cout << res.size() << "\n";
}