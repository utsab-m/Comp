#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

bool is_leap_year(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
}

int target(int month, int year) {
    switch (month) {
        case 1:
            return (is_leap_year(year)) ? 4 : 3;
        case 2:
            return (is_leap_year(year)) ? 29 : 28;
        case 3:
            return 0;
        case 4:
            return 4;
        case 5:
            return 9;
        case 6:
            return 6;
        case 7:
            return 11;
        case 8:
            return 8;
        case 9:
            return 5;
        case 10:
            return 10;
        case 11:
            return 7;
        case 12:
            return 12;
    }
    return -1;
}

bool is_sunday(int month, int year) {
    int targetDate = target(month, year);
    int c = year / 100, y = year % 100;

    int a = ((c % 4) * 5 + 2) % 7, s = y;

    if (s % 2 != 0) s += 11;
    s /= 2;

    if (s % 2 != 0) s += 11;

    s = -s % 7;

    int doomsday = a + s;
    int distance = targetDate - 1;

    return ((doomsday - distance) % 7 + 7 % 7) == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int sundays = 0;

    for (int year = 1901; year <= 2000; ++year) {
        for (int month = 1; month <= 12; ++month) {
            if (is_sunday(month, year)) ++sundays;
        }
    }

    cout << sundays << "\n";
}