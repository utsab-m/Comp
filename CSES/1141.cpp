#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int maxLength = 1;

    vector<int> playlist(n+1);
    for (int i = 1; i <= n; ++i) cin >> playlist[i];
    map<int, int> lastSeen;
    int l = 1;
    for (int r = 1; r <= n; ++r) {
        int song = playlist[r];

        if (lastSeen[song] >= l) {
            l = lastSeen[song]+1;
        }
        lastSeen[song] = r;

        maxLength = max(maxLength, r-l+1);
    }

    cout << maxLength << '\n';
}