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

        ll a = 0;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> leftXor(n);
        vector<int> rightXor(n);

        for (int i = 1; i < n; i++) {
            leftXor[i] = leftXor[i-1] ^ arr[i-1];
        }

        for (int i = n-2; i >= 0; i--) {
            rightXor[i] = rightXor[i+1] ^ arr[i+1];
        }

        int mx = 0;

        for (int i = 0; i < n; i++) {
            mx = max(mx, leftXor[i] ^ rightXor[i]);
        }

        cout << a << "\n";
    }
}