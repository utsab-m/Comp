#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print(string s) {
    cout << s << "\n";
}

void backtrack(string& s, unordered_set<string>& seen, int n) {
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            s[i] = '1';
            if (seen.find(s) != seen.end()) {
                s[i] = '0';
            } else {
                print(s);
                seen.insert(s);
                backtrack(s, seen, n);
            }
        } else {
            s[i] = '0';
            if (seen.find(s) != seen.end()) {
                s[i] = '1';
            } else {
                print(s);
                seen.insert(s);
                backtrack(s, seen, n);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    unordered_set<string> seen;
    string s = "";

    for (int i = 0; i < n; i++) {
        s += '0';
    }
    print(s);
    seen.insert(s);

    backtrack(s, seen, n);
}