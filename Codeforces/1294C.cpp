#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a = -1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                a = i;
                break;
            }
        }

        if (a == -1) {
            cout << "NO" << "\n";
            continue;
        }

        n /= a;

        int b = -1;
        for (int i = a+1; i * i <= n; i++) {
            if (n % i == 0) {
                b = i;
                break;
            }
        }

        if (b == -1) {
            cout << "NO" << "\n";
            continue;
        }

        n /= b;

        int c = n;

        if (c > b) {
            cout << "YES\n" << a << " " << b << " " << c << "\n";
        } else {
            cout << "NO\n";
        }
    }
}