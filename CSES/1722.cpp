#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    double sqrt5 = sqrt(5);
    double gr1 = (1+sqrt5) / 2, gr2 = (1-sqrt5) / 2;
    int mod = (int)(1e9+7);
    ll F_n = (ll)(1/sqrt5) * (pow(gr1, n) - pow(gr2, n));
    cout << F_n << "\n";
}