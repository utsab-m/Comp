#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num: nums) cin >> num;
    sort(nums.begin(), nums.end());

    ll MAX = 0;

    for (int num: nums) {
        if (MAX+1 < num) {
            cout << MAX+1 << '\n';
            return 0;
        } else {
            MAX += num;
        }
    }

    cout << MAX+1 << '\n';
}