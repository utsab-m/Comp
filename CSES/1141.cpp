#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> songs(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> songs[i];
    }

    int i = 1, j = 1;
    unordered_set<int> curr;
    int maxLength = INT_MIN;

    while (j <= n) {
        int id = songs[j];

        if (curr.find(id) != curr.end()) {
            while (songs[i] != id) {
                i++;
                curr.erase(songs[i]);
            }
            i++;
        }
        
        maxLength = max(maxLength, j - i + 1);

        curr.insert(songs[j]);
        j++;
    }

    cout << maxLength << "\n";
}