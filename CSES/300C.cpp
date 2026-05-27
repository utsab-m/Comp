#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    vector<bool> sums(64);
    sums[0] = true;

    for (int i = 1; i <= 64; i++) {
        if (i - a >= 0 && sums[i - a]) sums[i] = true;
        if (i - b >= 0 && sums[i - b]) sums[i] = true;
    }

    ll res = 0;

    

    cout << res % M << "\n";
}