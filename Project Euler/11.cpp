#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("11.txt");

    vector<vector<int>> grid(20, vector<int>(20));

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            file >> grid[i][j];
        }
    }

    ll maxProduct = 1;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            // get left, right, down, up, diag if possible
            ll product = 1;
            if (j - 3 >= 0) {
                for (int k = 0; k <= 3; k++) product *= grid[i][j-k];
                maxProduct = max(maxProduct, product);
                product = 1;
            }
            if (j + 3 < 20) {
                for (int k = 0; k <= 3; k++) product *= grid[i][j+k];
                maxProduct = max(maxProduct, product);
                product = 1;
            }
            if (i - 3 >= 0) {
                for (int k = 0; k <= 3; k++) product *= grid[i-k][j];
                maxProduct = max(maxProduct, product);
                product = 1;
            }
            if (i + 3 < 20) {
                for (int k = 0; k <= 3; k++) product *= grid[i+k][j];
                maxProduct = max(maxProduct, product);
                product = 1;
            }
            if (i + 3 < 20 && j + 3 < 20) {
                for (int k = 0; k <= 3; k++) product *= grid[i+k][j+k];
                maxProduct = max(maxProduct, product);
                product = 1;
            }
            if (i + 3 < 20 && j - 3 >= 0) {
                for (int k = 0; k <= 3; k++) product *= grid[i+k][j-k];
                maxProduct = max(maxProduct, product);
            }
        }
    }

    cout << maxProduct << "\n";
}