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

        vector<int> divisors(n+1);
        map<int, int> hops;
        int maxFrogs = 0;

        for (int i = 0; i < n; i++) {
            int hop;
            cin >> hop;
            hops[hop]++;
        }

        for (auto [hop, count]: hops) {
            for (int i = hop; i <= n; i += hop) {
                maxFrogs = max(maxFrogs, divisors[i] += count);
            }
        }
        
        cout << maxFrogs << "\n";
    }
}