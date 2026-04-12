#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int num_problems = 0;

    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a+b+c >= 2) {
            num_problems++;
        }
    }

    cout << num_problems << "\n";
}