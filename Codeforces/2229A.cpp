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

        int mn = 1001, mx = 0;

        for (int i = 0; i < n; i++) {
            int x; 
            cin >> x;
            
            mn = min(mn, x);
            mx = max(mx, x);
        }

        int avg = (mx + mn) / 2;

        cout << max(avg - mn, mx - avg) << "\n";
    }
    
}