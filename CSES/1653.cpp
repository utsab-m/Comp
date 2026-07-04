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

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                auto prev = dp[mask ^ (1 << i)];

                int current_rides = prev.first, current_weight = prev.second;

                // person fits in elevator
                if (weights[i] + current_weight <= x) {
                    current_weight += weights[i];
                }
                // person doesn't fit in elevator
                else {
                    current_rides++;
                    current_weight = weights[i];
                }

                dp[mask] = min(dp[mask], {current_rides, current_weight});
            }
        }
    }

    cout << dp[(1 << n) - 1].first << '\n';
}