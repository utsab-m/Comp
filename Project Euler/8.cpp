#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll = long long;

ll get_product(string s) {
    ll product = 1;
    for (char c: s) product *= (c - '0');
    return product;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("8.txt");
    string s;
    getline(file, s);

    ll maxProduct = 1;

    for (int i = 0; i <= s.size() - 13; i++) {
        maxProduct = max(maxProduct, get_product(s.substr(i, 13)));
    }

    cout << maxProduct << "\n";
}