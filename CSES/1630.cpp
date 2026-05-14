#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> tasks;

    for (int i = 1; i <= n; i++) {
        int a, d;
        cin >> a >> d;

        tasks.push_back({a, d});
    }

    sort(tasks.begin(), tasks.end());

    ll reward = 0;
    ll time = 0;

    for (auto [a, d]: tasks) {
        time += a;

        reward += d - time;
    }

    cout << reward << "\n";
}