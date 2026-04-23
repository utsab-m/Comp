#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll res = 0;

    vector<int> nums(n);
    map<int, int> count;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        count[nums[i]]++;
    }

    for (int i = 0; i < n; i++) {
        ll ways = (1 << count.size() - 1);

        for (auto c: count) {
            if (c.first != nums[i]) {
                ways = (ways * c.second) % (int)(10e9+7);
            }
        }

        res = (res + ways) % (int)(10e9+7);

        count[nums[i]]--;
        if (!count[nums[i]]) count.erase(nums[i]);
    }

    cout << res << "\n";
}