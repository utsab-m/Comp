#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve(int n) {
    vector<string> grid(n, string(n, '.'));
    grid[n-1][n-2] = 'C';
    grid[n-2][n-1] = 'C';

    for (int i=0; i<n; ++i) {
        cout << grid[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        solve(n);
    }
}