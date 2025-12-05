#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    ll res = 2;

    for (int i = 1; i < n; i++) {
        res *= 2;
        res = res % (ll)(pow(10, 9) + 7);
    }

    cout << res;
}