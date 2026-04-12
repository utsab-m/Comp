#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int k = n;

        while (n != 0) {
            k--;
            n &= k;
        }

        cout << k << "\n";
    }
}