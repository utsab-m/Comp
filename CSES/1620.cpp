#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll t;
    cin >> n >> t;

    int mn = INT_MAX;
    vector<int> times(n);
    for (int& time: times) {
        cin >> time;
        mn = min(mn, time);
    }

    ll l = 0, r = mn * t;
    ll res = 0;

    while (l <= r) {
        ll m = (r+l) / 2;

        ll products = 0;
        for (int time: times) products += (m / time);

        if (products >= t) {
            res = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }

    cout << res << "\n";
}