#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ld> a(8), b(8);
    for (int i=0; i<8; ++i) {
        cin >> a[i] >> b[i];
    }

    ld maxProb = 0;

    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            if (j == i) continue;
            for (int k=j+1; k<8; ++k) {
                if (k == i) continue;
                for (int l=k+1; l<8; ++l) {
                    if (l == i) continue;
                    double probA = a[i] + b[j], probB = a[i] + b[k], probC = a[i] + b[l];
                    maxProb = max(maxProb, (a[i] * a[i] * a[i]) / (probA * probB * probC));
                }
            }
        }
    }

    cout << fixed << setprecision(9) << maxProb << '\n';
}