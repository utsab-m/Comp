#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    ll c = (n * (n + 1)) / 2;

    ll s = 0;

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;

        s += x;
    }

    cout << c - s;
}