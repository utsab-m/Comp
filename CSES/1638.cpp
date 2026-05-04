#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> ways(n, vector<int>(n));
    ways[0][0] = 1;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            char ch;
            cin >> ch;

            if (ch == '*') ways[r][c] = 0;
            else {
                if (c-1 >= 0) (ways[r][c] += ways[r][c-1]) %= M;
                if (r-1 >= 0) (ways[r][c] += ways[r-1][c]) %= M;
            }
        }
    }

    cout << ways[n-1][n-1] << "\n";
}