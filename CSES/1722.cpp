#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ull n;
    cin >> n;

    double sqrt5 = sqrt(5);
    double gr1 = (1+sqrt5) / 2, gr2 = (1-sqrt5) / 2;
    int mod = (int)(1e9+7);
    ll F_n = (((ll)((1/sqrt5) * (pow(gr1, n) - pow(gr2, n))) % mod) + mod) % mod;
    cout << F_n << "\n";
}