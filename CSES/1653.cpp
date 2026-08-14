#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for (int& weight: weights) cin >> weight;

    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); ++mask) {
        dp[mask] = {n+1, 0};

        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) {
                auto prev = dp[mask ^ (1 << j)];

                int rides = prev.first, weight = prev.second;

                if (weights[j] + weight > x) {
                    weight = weights[j];
                    ++rides;
                } else {
                    weight += weights[j];
                }

                dp[mask] = min(dp[mask], {rides, weight});
            }
        }
    }

    cout << dp[(1 << n) - 1].first << '\n';

}