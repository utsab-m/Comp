#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    int maxCustomers = 1, customers = 0;

    sort(events.begin(), events.end());

    for (auto event: events) {
        customers += event.second;
        maxCustomers = max(maxCustomers, customers);
    }

    cout << maxCustomers << "\n";
}