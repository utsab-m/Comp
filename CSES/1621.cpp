#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> nums;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if (nums.find(x) == nums.end()) nums.insert(x);
    }

    cout << nums.size() << "\n";
}