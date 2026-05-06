#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<int> mp(26, 0);
string res;

void backtrack(string& solution, int s) {
    if (solution.size() == s) {
        res = solution;
        return;
    }

    for (int i = 0; i < 26; i++) {
        char c = 'A' + i;
        int n = mp[i];

        if (solution.empty()) solution.push_back(c);
        else if (mp[c] > 0 && c != solution.back()) {
            mp[c]--;
            solution.push_back(c);
            backtrack(solution, s);
            solution.pop_back();
            mp[c]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int size = s.size(), maxSize = -1;

    for (char c: s) {
        mp[c]++;
        maxSize = max(maxSize, mp[c]);
    }

    string solution;

    if ((size + 1) / 2 >= maxSize) {
        backtrack(solution, size);
        cout << res << "\n";
    } else {
        cout << -1 << "\n";
    }
}