#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n);
    ll sum = 0;

    for (int& p_i: p) {
        cin >> p_i;
    }

    sort(p.begin(), p.end());

    int median;

    if (n % 2 == 1) {
        median = p[n / 2];
    } else {
        median = (p[n / 2] + p[n / 2 - 1]) / 2;
    }

    ll diff = 0;

    for (int num: p) diff += abs(median - num);

    cout << diff << "\n";
}