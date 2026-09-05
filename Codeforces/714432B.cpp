#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l = 1, r = 1e6, m;

    while (l < r) {
        m = l + (r-l) / 2;
        cout << m << '\n';
        fflush(stdout);
        string sign;
        cin >> sign;

        if (sign == "<") {
            r = m-1;
        } else {
            l = m;
        }
    }

    cout << "! " << m << '\n';
}