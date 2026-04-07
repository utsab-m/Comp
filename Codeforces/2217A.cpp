#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        ll totalSum = 0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            totalSum += num;
        }

        if (totalSum % 2 == 1) {
            cout << "YES" << "\n";
        } else if (k * n % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}