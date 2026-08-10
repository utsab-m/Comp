#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> pref(n+1);
    
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;

        pref[i] = pref[i-1] ^ val;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << (pref[b] ^ pref[a-1]) << '\n'; 
    }
}