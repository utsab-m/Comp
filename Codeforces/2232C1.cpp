#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, s;
        cin >> n >> x >> s;
        
        string u;
        cin >> u;

        ll res = 0;
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(x+1, vector<ll>(x+1)));

        for (int i = 0; i < n; ++i) {
            char type = u[i];
            for (int e = 0; e <= x; ++e) {
                for (int p = 0; p <= x - e; ++p) {
                    // Choice 1: kick out
                    if (i-1 >= 0) dp[i][e][p] = max(dp[i][e][p], dp[i-1][e][p]);
                    
                    // Choice 2: seat
                    if (type == 'I') {
                        
                    } else if (type == 'E') {

                    } else {

                    }
                }
            }
        }

        cout << res << "\n";
    }
}