#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int c = n*(n-1)/2;
    vector<int> b(c);
    for (int i=0; i<c; ++i) cin >> b[i];
    sort(b.begin(), b.end());

    int i=0, j=n-1;
    for (int k=0; k<n-1; ++k) {
        cout << b[i] << ' ';
        i += j;
        --j;
        
    }
    cout << (int)1e9 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}