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

        vector<int> a(n), b(n);
        
        for (int& a_i: a) cin >> a_i;
        for (int& b_i: b) cin >> b_i;

        int mx = 0, sum = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                mx = max(mx, b[i]);
                sum += a[i];
            } else {
                mx = max(mx, a[i]);
                sum += b[i];
            }
        }

        cout << sum + mx << "\n";
    }
}