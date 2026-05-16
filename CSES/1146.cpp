#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll calc(ll x, map<ll, ll>& bits) {
    if (bits[x] || x == 0) return bits[x];

    if (x % 2 == 0) {
        bits[x] = calc(x/2 - 1, bits) + calc(x/2, bits) + x/2;
        return bits[x];
    } else {
        bits[x] = 2 * calc(x/2, bits) + x/2 + 1;
        return bits[x];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    map<ll, ll> bits;
    bits[0] = 0;
    bits[1] = 1;

    cout << calc(n, bits) << "\n";
}