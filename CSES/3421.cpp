#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int mod = (int)(1e9+7);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll res = 1;

    vector<int> nums(n);
    unordered_map<int, int> count;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        count[nums[i]]++;
    }

    for (auto it: count) {
        res = ((res % mod) * (it.second + 1)) % mod;
    }

    cout << res - 1 << "\n";
}