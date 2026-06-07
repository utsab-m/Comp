#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> locs(n);
        
        for (int i = 0; i < n; i++) {
            cin >> locs[i];
        }

        sort(locs.begin(), locs.end());
        
        int i = 0, j = n-1;

        int calls = 0;

        while (i < j) {
            if (locs[i] == locs[j]) break;
            else calls++;
            i++;
            j--;
        }

        cout << calls << "\n";
    
    }
}