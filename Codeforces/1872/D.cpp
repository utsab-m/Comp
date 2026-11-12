#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll n, x, y; cin >> n >> x >> y;

    ll d = (x*y)/gcd(x, y);
    ll c = n/d;
    ll a  = n/x - c, b = n/y - c;

    cout << a*(n+1) - a*(a+1)/2 - b*(b+1)/2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}