#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    ll z = 0;

    while (n > 0) {
        n /= 5;
        z += n;
    }

    cout << z;
}