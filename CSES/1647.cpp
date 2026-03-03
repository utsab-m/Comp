#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        x[i] = t;
    }

    int k = floor(log2(n));

    vector<vector<int>> sparse(k+1, vector<int>(n));

    copy(x.begin(), x.end(), sparse[0].begin());

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j + (1 << (i - 1))]);
        }
    }

    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;

        int length = b - a + 1;
        int power = floor(log2(length));
        int j = 1 << power;

        cout << min(sparse[power][a-1], sparse[power][b - j]) << "\n";
    }
}