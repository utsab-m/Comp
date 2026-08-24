#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void add(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    
    vector<int> dp(1 << H);
    const int FULL = (1 << H) - 1;
    dp[FULL] = 1;

    for (int c = 0; c < W; ++c) {
        for (int r = 0; r < H; ++r) {
            vector<int> new_dp(1 << H);
            for (int mask = 0; mask < (1 << H); ++mask) {
                if (!(mask & (1 << r))) {
                    add(new_dp[mask ^ (1 << r)], dp[mask]);
                } else {
                    if (r != 0 && !(mask & (1 << (r-1)))) {
                        add(new_dp[mask | (1 << r) | (1 << (r-1))], dp[mask]);
                    }
                     add(new_dp[mask ^ (1 << r)], dp[mask]);
                }
            }
            dp = new_dp;
        }
    }

    cout << dp[FULL] << '\n';
}