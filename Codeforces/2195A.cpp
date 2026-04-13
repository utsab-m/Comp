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

        bool sixty_seven = false;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            if (a == 67) {
                sixty_seven = true;
            }
        }

        if (sixty_seven) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n"; 
        }
    }
}