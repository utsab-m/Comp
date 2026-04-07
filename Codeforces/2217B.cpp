#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n+1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int p;
        cin >> p;

        int x = a[p];
        ll ops = 0;
        int i = 1, j = n;

        while (i <= j) {
            x = !x;
            while (i <= j && a[i] != x) i++;
            while (i <= j && a[j] != x) j--;
            if (i <= j) ops++;
        }

        cout << ops << "\n";
    }
}