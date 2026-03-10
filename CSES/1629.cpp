#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<pair<int, int>> times;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        times.push_back({b, a});
    }

    sort(times.begin(), times.end());

    int curr = times[0].first;
    int movies = 1;

    for (int i = 1; i < n; i++) {
        if (times[i].second >= curr) {
            curr = times[i].first;
            movies++;
        }
    }

    cout << movies << "\n";
}