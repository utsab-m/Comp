#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll d[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    d[1] = 0;
    d[2] = 1;
    for (int i = 3; i <= 1000000; i++) {
        (d[i] = (i-1) * (d[i-1] + d[i-2])) %= MOD;
    }

    cout << d[n] << "\n";
}