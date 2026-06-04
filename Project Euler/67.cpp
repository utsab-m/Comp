#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("67.txt");

    vector<vector<int>> grid(100, vector<int>(100));
    int maxPathSum = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            file >> grid[i][j];

            int up = 0, upLeft = 0;

            if (i-1 >= 0) up = grid[i-1][j];
            if (i-1 >= 0 && j-1 >= 0) upLeft = grid[i-1][j-1];

            grid[i][j] += max(up, upLeft);

            maxPathSum = max(maxPathSum, grid[i][j]);
        }
    }

    cout << maxPathSum << "\n";
}