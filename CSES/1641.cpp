#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int& num: arr) cin >> num; 
    unordered_map<int, int> seen;

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int sum = arr[i] + arr[j];
            int left = x - sum;
            if (seen.find(left) != seen.end() && seen[left] != i && seen[left] != j) {
                cout << (i+1) << ' ' << (j+1) << ' ' << (seen[left]+1) << '\n';
                return 0;
            }
            seen[arr[j]] = j;
        }
        seen[arr[i]] = i;
    }

    cout << "IMPOSSIBLE" << '\n';
}