#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    vector<int> nums(3);
    for (int i=0; i<3; ++i) cin >> nums[i];

    sort(nums.begin(), nums.end());

    if (nums[0] == nums[1] - 1 && nums[2] == nums[1] + 1) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}