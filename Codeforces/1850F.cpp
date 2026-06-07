#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> hops(n), divisors(n+1);
        int maxFrogs = 0;

        for (int& hop: hops) cin >> hop;

        for (int i = 1; i <= n; i++) {
            for (int j = hops[i-1]; j <= n; j += hops[i-1]) {
                maxFrogs = max(maxFrogs, ++divisors[j]);
            }
        }
        
        cout << maxFrogs << "\n";
    }
}