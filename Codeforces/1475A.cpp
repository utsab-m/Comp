#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;

        while (n && n % 2 == 0) {
            n /= 2;
        }

        if (n % 2 == 0 || n == 1) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}