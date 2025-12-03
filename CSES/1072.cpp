#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// int invalid(int k) {
//     unordered_map<vector<int>, vector<int>> mp;

//     for (int r = k; r )
// }

ll numWays(int k) {
    ll totalSquares = k * k;
    ll ways = 0;

    if (totalSquares >= 2) {
        ways = (totalSquares * (totalSquares - 1)) / 2;
    }
    
    if (totalSquares >= 3) {
        ways -= 4 * (k - 1) * (k - 2);
    }

    return ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        cout << numWays(k) << "\n";
    }
}