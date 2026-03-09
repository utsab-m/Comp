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

        times.push_back({a, b});
    }

    sort(times.begin(), times.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;

    int maxNumber = 1;

    pq.push(times[0].second);

    for (int i = 1; i < n; i++) {
        auto time = times[i];
        int arrive = time.first, leave = time.second;

        int top = pq.top();

        while (!pq.empty() && top < arrive) {
            pq.pop();
            if (!pq.empty()) top = pq.top();
        }
        pq.push(leave);

        maxNumber = max(maxNumber, (int)pq.size());
    }

    cout << maxNumber << "\n";
}