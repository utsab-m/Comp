#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool inb(ll num, ll l, ll r) {
    return l <= num && num <= r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n=1e12+1;

    ll l, r; cin >> l >> r;

    vector<ll> tri;
    ll count=0;

    for (ll i=1; (i*(i+1)/2)<=n; ++i) {
        tri.push_back(i*(i+1)/2);
    }

    ll small, big;

    ll i=0, j=tri.size()-1;

    while (i<j) {
        ll m = i + (j-i) / 2;

        if (tri[m] < l) {
            i=m+1;
        } else {
            j=m;
        }
    }

    small=i;

    i=0; j=tri.size()-1;

    while (i<j) {
        ll m = i + (j-i+1) / 2;

        if (tri[m] > r) {
            j=m-1;
        } else {
            i=m;
        }
    }

    big = j;

    if (tri[big])

    cout <<  (inb(tri[big], l, r) && inb(tri[small], l, r) ? (big - small + 1) : 0) << '\n';

}