#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> nums(n+1);
    int bitmask=0;
    for (int i=1; i<=n; ++i) {
        cin >> nums[i];
        nums[i] = __builtin_popcount(nums[i]) % 2;
        bitmask += nums[i];
    }

    cout << n-bitmask << ' ';

    for (int i=0; i<q; ++i) {
        int p, x;
        cin >> p >> x;

        bitmask -= nums[p];
        nums[p] = (__builtin_popcount(x) % 2);
        bitmask += nums[p];

        cout << n-bitmask << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}