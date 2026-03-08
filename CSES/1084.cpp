#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n);
    vector<int> sizes(m);

    for (int i = 0; i < n; i++) {
        int n_i;
        cin >> n_i;

        desired[i] = n_i;
    }

    for (int i = 0; i < m; i++) {
        int m_i;
        cin >> m_i;

        sizes[i] = m_i;
    }

    sort(desired.begin(), desired.end());
    sort(sizes.begin(), sizes.end());

    int res = 0;

    int j = 0;

    for (int i = 0; i < n; i++) {
        int x = desired[i];
        int lb = x - k, ub = x + k;
        while (j < m && sizes[j] < lb) {
            j++;
        }
        if (j < m && lb <= sizes[j] && sizes[j] <= ub) {
            res++;
            j++;
        }
    }

    cout << res << "\n";
}