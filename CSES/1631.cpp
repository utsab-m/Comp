#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> times(n);

    ll sum = 0;

    for (int& time: times) {
        cin >> time;
        sum += time;
    }

    sort(times.begin(), times.end());
    
    ll res;

    if (sum - times.back() < times.back()) {
        res = 2 * times.back();
    } else {
        res = sum;
    }
    
    cout << res << "\n";
}