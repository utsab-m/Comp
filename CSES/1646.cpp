#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;

    vector<ll> prefixSum(n+1, 0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        
        prefixSum[i] = prefixSum[i-1] + x;
    }

    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;

        cout << prefixSum[b] - prefixSum[a-1] << "\n";
    }
}