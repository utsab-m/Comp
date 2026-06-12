#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int MAX = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> freq(MAX+1);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        freq[x]++;
    }

    int res = 1;

    for (int i = MAX; i >= 2; --i) {
        int multiples = 0;

        for (int j = i; j <= MAX; j += i) {
            multiples += freq[j];
        }

        if (multiples > 1) {
            res = i;
            break;
        }
    }
    
    cout << res << "\n";
}