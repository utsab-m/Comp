#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (b == 0) {
            cout << 1 << "\n";
        } else {
            vector<int> binary((int)log2(n) + 1);
            binary.push_back(a);

            int j = 1;
            while ((1 >> j) < b) {
                binary[j] = (binary[j-1] * binary[j-1]) % ((int)1e9 + 7);
                j++;
            }

            int exp = 1;
            int base = b;

            while (base != 0) {
                if ((1 >> j) < base) {
                    exp = (exp * binary[j]) % ((int)1e9 + 7);
                    base -= (1 << j);
                } else {
                    j--;
                }
            }

            cout << exp << "\n";
        }
    }
}