#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int x = 0;

    while (n--) {
        string o;
        cin >> o;

        if (o[1] == '+') {
            x++;
        } else {
            x--;
        }
    }

    cout << x << "\n";
}