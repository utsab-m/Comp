#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

struct Project {
    int start, end, reward;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Project> projects(n);
    vector<ll> dp(n+1);

    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) {
        return a.end < b.end;
    });

    for (int i = 1; i <= n; ++i) {
        // don't choose it
        dp[i] = dp[i-1];

        // choose it
        Project target;
        target.end = projects[i-1].start;

        auto it = lower_bound(projects.begin(), projects.begin() + (i-1), target, [](const Project& a, const Project& b) {
            return a.end < b.end;
        });

        int idx = distance(projects.begin(), it);

        dp[i] = max(dp[i], (ll)projects[i-1].reward + dp[idx]);
    }

    cout << dp[n] << '\n';
}