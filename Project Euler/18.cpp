#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll maxPathSum(vector<vector<int>>& grid, int i, int j) {
    if (i >= 15 || j >= 15) return 0;
    return grid[i][j] + max(maxPathSum(grid, i+1, j), maxPathSum(grid, i+1, j+1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("18.txt");

    vector<vector<int>> grid(15, vector<int>(15));

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            file >> grid[i][j];
        }
    }

    cout << maxPathSum(grid, 0, 0) << "\n";
}