#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    int ans = 1;

    int lastNum;
    cin >> lastNum;

    vector<int> nums;
    nums.push_back(lastNum);

    for (int i=1; i<n; ++i) {
        int currNum; cin >> currNum;
        if (currNum != lastNum) nums.push_back(currNum);
        lastNum = currNum;
    }

    int m = nums.size();
    int i=1;

    while (i<m) {
        if (nums[i-1] > nums[i]) {
            while (i<m && nums[i-1] > nums[i] && (i+1<m && nums[i] > nums[i+1])) {
                ++i;
            }
            ++ans;
            ++i;
        } else {
            while (i<m && nums[i-1] < nums[i] && (i+1<m && nums[i] < nums[i+1])) {
                ++i;
            }
            ++ans;
            ++i;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}