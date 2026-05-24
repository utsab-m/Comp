#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int bills[] = {1,5,10,20,100};

    int num = 0;

    for (int i = size(bills)-1; i >= 0; i--) {
        if (bills[i] <= n) {
            num += (n / bills[i]);
            n %= bills[i];
        }
    }

    cout << num << "\n";
}