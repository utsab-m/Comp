#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        ll minH = 1e9, runningSum = 0;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            runningSum += nums[i];
            minH = min(minH, runningSum / (i+1));

            cout << minH << " ";
        }
        cout << "\n";

    }
}