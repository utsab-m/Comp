#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("13.txt");

    int M = 100, N = 50;
    
    string res = "";
    vector<string> grid(M);

    for (int i = 0; i < M; ++i) {
        file >> grid[i];
        cout << grid[i] << '\n';
    }

    int carry = 0, sum = 0;

    for (int j = N-1; j >= 0; j--) {
        sum = carry;
        for (int i = M-1; i >= 0; i--) {
            sum += grid[i][j] - '0';
        }
        res = to_string(sum % 10) + res;
        carry = sum / 10;
    }

    res = to_string(carry) + res;

    cout << res.length() << "\n";
    cout << res.substr(0, 10) << "\n";
}