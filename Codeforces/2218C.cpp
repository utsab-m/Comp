#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> res(3 * n);
        for (int i = 1; i <= n; i++) {
            int index = (i-1) * 3;
            res[index] = i;
            res[index+1] = n + (i * 2);
            res[index+2] = n + (i * 2) - 1;
        }

        for (int i = 0; i < 3 * n; i++) {
            cout << res[i] << " ";
        }
    }
}