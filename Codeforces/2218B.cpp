#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll sum = 0;
        int mx = -67;

        for (int j = 0; j < 7; j++) {
            int num;
            cin >> num;

            sum += num;
            mx = max(mx, num);
        }

        cout << 2 * mx - sum << "\n";
    }
    
}