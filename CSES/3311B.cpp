#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char ch;
            cin >> ch;

            char l = 'A';

            while(l == ch || (c - 1 >= 0 && grid[r][c-1] == l) || (r - 1 >= 0 && grid[r-1][c] == l)) l++;

            grid[r][c] = l;
            cout << l;
        }
        cout << "\n";
    }

}