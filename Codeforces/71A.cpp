#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string w;
        cin >> w;

        if (w.size() > 10) {
            cout << w.front() << w.size() - 2 << w.back() << "\n";
        } else {
            cout << w << "\n";
        }
    }
}