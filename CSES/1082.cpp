#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll res = 0;

    for (int i = 1; i <= n; i++) {
        (res += i * (n / i)) %= MOD;
    }

    cout << res << "\n";
}