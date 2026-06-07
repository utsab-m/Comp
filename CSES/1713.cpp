#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int MAX = 1e6;
    vector<int> divisors(MAX+1);

    for (int i = 1; i <= MAX; i++) {
        for (int j = i; j <= MAX; j += i) {
            divisors[j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cout << divisors[x] << "\n";
    }
}