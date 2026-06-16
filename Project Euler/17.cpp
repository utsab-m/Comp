#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

map<int, int> c = {
    {1, 3},
    {2, 3},
    {3, 5},
    {4, 4},
    {5, 4},
    {6, 3},
    {7, 5},
    {8, 5},
    {9, 4},
    {10, 3},
    {11, 6},
    {12, 6},
    {13, 8},
    {14, 8},
    {15, 7},
    {16, 7},
    {17, 9},
    {18, 8},
    {19, 8},
    {20, 6},
    {30, 6},
    {40, 5},
    {50, 5},
    {60, 5},
    {70, 7},
    {80, 6},
    {90, 6},
    {100, 7}
};

int count_chars(int num) {
    if (num == 1000) return c[1] + 8; // if one thousand, 3 + 8 chars
    int chars = 0;
    int last_two = num % 100; // get the last 2 digits
    if (last_two <= 20) chars += c[last_two]; // if it's at most 20, we alr have it in the map
    else {
        chars += c[last_two / 10 * 10]; // get the tens place value
        chars += c[last_two % 10]; // get the ones place value
    }
    if (num >= 100) {
        if (chars != 0) chars += 3;
        chars += c[num / 100] + c[100];
    }
    return chars;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int sol = 0;

    for (int i = 1; i <= 1000; ++i) {
        sol += count_chars(i);
    }

    cout << sol << '\n';
}