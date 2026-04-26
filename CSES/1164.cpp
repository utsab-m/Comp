#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> customers(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        cin >> customers[i].first.first >> customers[i].first.second;
        customers[i].second = i;
    }

    sort(customers.begin(), customers.end());

    vector<int> roomAssigned(n);
    int roomId = 1;

    for (int i = 0; i < n; i++) {
        int a = customers[i].first.first, b = customers[i].first.second;
        int order = customers[i].second;

        if (pq.empty()) {
            roomAssigned[order] = roomId++;
            pq.push({b, roomId-1});
        } else {
            auto top = pq.top();

            if (a <= top.first) {
                roomAssigned[order] = roomId++;
                pq.push({b, roomId-1});
            } else {
                roomAssigned[order] = top.second;
                pq.pop();
                pq.push({b, top.second});
            }
        }
    }

    cout << roomId - 1 << "\n";
    for (int i = 0; i < n; i++) {
        cout << roomAssigned[i] << " ";
    }
}