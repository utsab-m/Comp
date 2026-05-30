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
        
        int m = locs.size() / 2;
        int i = m - 1, j = m + 1;

        int calls = 0;

        while (i >= 0 || j < n) {
            while (i >= 0 && locs[i] == locs[m]) i--; 
            while (j < n && locs[j] == locs[m]) j++; 
            calls++;
            i--;
            j++;
        }

        cout << calls << "\n";
    }
    
}