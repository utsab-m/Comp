#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

double ways = 0, totalWays = 1;

void backtrack(string& s, int i, int pos, int endPos) {
    if (i == s.size()) {
        if (pos == endPos) ways++;
    } else {
        if (s[i] == '?') {
            backtrack(s, i+1, pos+1, endPos);
            backtrack(s, i+1, pos-1, endPos);
        } else if (s[i] == '+') backtrack(s, i+1, pos+1, endPos);
        else backtrack(s, i+1, pos-1, endPos);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int endPos = 0;
    for (char c: s1) {
        if (c == '+') endPos++;
        else endPos--;
    }
    for (char c: s2) if (c == '?') totalWays *= 2;

    backtrack(s2, 0, 0, endPos);

    cout << fixed << setprecision(12);
    cout << ways / totalWays << "\n";
}