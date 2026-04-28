#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool evenOrOdd = true;
    int even = -1, odd = -1;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        if (a % 2 == 0) {
            if (even != -1) {
                evenOrOdd = false;
                if (odd != -1) {
                    break;
                }
            }
            even = i;
        } else {
            if (odd != -1) {
                evenOrOdd = true;
                if (even != -1) {
                    break;
                }
            }
            odd = i;
        }
    }

    if (evenOrOdd) {
        cout << even << "\n";
    } else {
        cout << odd << "\n";
    }
}