#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    int res = 0;
    
    while (x > 0) {
        if (x & 1) ++res;        
        x >>= 1;
    }

    cout << res << "\n";
}