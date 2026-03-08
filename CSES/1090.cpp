#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;

    vector<int> p(n);

    for (int& p_i: p) {
        cin >> p_i;
    }

    sort(p.begin(), p.end(), greater<int>());

    int h = 0, l = n-1;

    int gondolas = 0;

    while (h <= l) {
        gondolas++;
        if (h == l) break;
        if (p[h] + p[l] > x) h++;
        else {
            h++;
            l--;
        }
    }

    cout << gondolas << "\n";

 }