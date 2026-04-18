#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    ll ways = 0;
    int bars = n - 1;
    int stars = a - n;

    while (stars <= b - n) {
        ll curr = 1;

        for (int i = stars; i >= stars - bars + 1; i--) {
            curr *= i;
        }

        for (int i = bars; i >= 2; i--) {
            curr /= i;
        }

        ways += curr;
    }

    cout << ways << "\n";
}