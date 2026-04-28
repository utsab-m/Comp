#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        int c = n - (a + b);

        if (c < 0 || ((a == 0 || b == 0) && c < n)) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";

            vector<int> a_res(n+1);
            vector<int> b_res(n+1);

            int a_l = c+1, a_u = n, b_l = c+1, b_u = n;
            int i = 1;

            while (i <= c) {
                a_res[i] = i++;
                b_res[i] = i++;
            }

            if (b > a) {
                b_u = b_u - b;
                for (int j = 1; j <= b; j++) {
                    b_res[i] = b_u + j;
                    a_res[i] = a_l++;
                    i++;
                }
                for (int j = 1; j <= a; j++) {
                    a_res[i] = a_l++;
                    b_res[i] = b_l++; 
                }
            } else {
                a_u = a_u - a;
                for (int j = 1; j <= a; j++) {
                    a_res[i] = a_u + j;
                    b_res[i] = b_l++;
                    i++;
                }
                for (int j = 1; j <= b; j++) {
                    a_res[i] = a_l++;
                    b_res[i] = b_l++; 
                }
            }

            for (i = 1; i <= n; i++) {
                cout << a_res[i] << " ";
            }
            cout << "\n";
            for (i = 1; i <= n; i++) {
                cout << b_res[i] << " ";
            }
            cout << "\n";

        }
    }
}