#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<int> indices(n+1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        indices[x] = i;
    }

    int times = 1;

    for (int i = 2; i <= n; i++) {
        if (indices[i-1] > indices[i]) times++;
    }

    cout << times << "\n";
}