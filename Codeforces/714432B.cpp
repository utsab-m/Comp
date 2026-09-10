#include "bits/stdc++.h"
#include <cstdio>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l = 1, r = 1e6, m = l + (r-l) / 2;
    cout << m << '\n';

    while (l < r) {
        fflush(stdout);
        string sign;
        cin >> sign;        

        if (sign == "<") {
            r = m-1;
        } else {
            l = m;
        }
        m = l + (r-l) / 2;
        cout << m << '\n';
    }

    cout << "! " << m << '\n';
}