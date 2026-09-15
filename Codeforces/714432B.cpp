#include "bits/stdc++.h"
#include <cstdio>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l = 1, r = 1e6;
    

    while (l < r) {
        int m = l + (r-l+1) / 2;
        cout << m << endl;

        string sign;
        cin >> sign;        

        if (sign == "<") {
            r = m-1;
        } else {
            l = m;
        }
    }

    cout << "! " << l << endl;
}