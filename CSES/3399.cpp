#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void raab(int n, int a, int b) {
    int c = n - (a + b);
    if (a + b > n || (c == 1 && (a == 0 || b == 0))) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, a, b;
        cin >> n >> a >> b;

        raab(n, a, b);
    }
}