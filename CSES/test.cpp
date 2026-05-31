#include "bits/stdc++.h"

using namespace std;

void print128(__int128 x) {
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    if (x > 9) {
        print128(x / 10);
    }
    cout << (char)('0' + (x % 10));
}

int main() {
    __int128 large_number = 1234567890123456789123; 
    print128(large_number);
}