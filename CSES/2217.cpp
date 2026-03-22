#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> x(n+1);
    vector<int> nums(n+1);

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        x[a] = i;
        nums[i] = a;
    }

    int rounds = 1;

    for (int i = 1; i <= n; i++) {
        if (x[i-1] > x[i]) rounds++;
    }

    set<pair<int, int>> updates;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        if (nums[a] - 1 >= 1) {
            updates.insert({nums[a] - 1, nums[a]});
        }
        if (nums[a] + 1 <= n) {
            updates.insert({nums[a], nums[a] + 1});
        }
        if (nums[b] - 1 >= 1) {
            updates.insert({nums[b] - 1, nums[b]});
        }
        if (nums[b] + 1 <= n) {
            updates.insert({nums[b], nums[b] + 1});
        }

        for (auto update: updates) {
            int l = update.first, r = update.second;

            if (x[l] > x[r]) rounds--;
        }

        swap(nums[a], nums[b]);
        swap(x[nums[a]], x[nums[b]]);

        for (auto update: updates) {
            int l = update.first, r = update.second;

            if (x[l] > x[r]) rounds++;
        }

        updates.clear();

        cout << rounds << "\n";
    }

}