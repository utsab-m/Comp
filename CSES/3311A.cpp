#include "bits/stdc++.h"
using namespace std;

void backtrack(vector<string>& grid, int r, int c) {
    if (c == grid[0].size()) backtrack(grid, r+1, 0);
    if (r == grid.size()) return;

    char curr = grid[r][c];

    for (char c='A'; c <= 'D'; c++) {
        if (c != curr &&
            (r-1 < 0 || (r-1 >= 0 && grid[r-1][c] != c)) &&
            (c-1 < 0 || (c-1 >= 0 && grid[r][c-1] != c))
        ) {
            grid[r][c] = c;
            backtrack(grid, c+1, r);
            grid[r][c] = curr;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n; cin >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    backtrack(grid, 0, 0);

    for (string s: grid) {
        cout << s << "\n";
    }
}