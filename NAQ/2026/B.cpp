#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> alts(n);
    set<int> sets;

    for (int& a: alts) cin >> a;

    for (int i=1; i<n-1; ++i) {
        if (alts[i]-alts[i-1] > alts[i+1]-alts[i]) {
            sets.insert(i);
        }
    }

    cout << sets.size() << '\n';
}