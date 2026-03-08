#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, h, t;
    cin >> n >> m;

    multiset<int> ticketPrices;

    for (int i = 0; i < n; i++) {
        cin >> h; 
        ticketPrices.insert(h);
    }

    for (int i = 0; i < m; i++) {
        cin >> t;

        auto it = ticketPrices.upper_bound(t);
        if (it == ticketPrices.begin()) {
            cout << -1 << "\n";
        } else {
            it--;
            cout << *it << "\n";
            ticketPrices.erase(it);
        }
    }

}