#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void print(vector<char>& s) {
    for (char c: s) cout << c;
    cout << "\n";
}
 
void backtrack(vector<char>& s, vector<int>& count, int total) {
    if (s.size() == total) {
        print(s);
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            s.push_back((char)('a' + i));
            count[i]--;
            backtrack(s, count, total);
            count[i]++;
            s.pop_back();
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    vector<int> factorial(9, 1);
 
    for (int i = 1; i <= 8; i++) {
        factorial[i] = i * factorial[i - 1];
    }
    
    string s;
    cin >> s;
 
    int combos = factorial[s.size()];
 
    vector<int> count(26, 0);
 
    for (char c: s) count[c - 'a']++;
 
    for (int num: count) if (num != 0) combos /= factorial[num];
 
    cout << combos << "\n";
 
    vector<char> v = {};
 
    backtrack(v, count, s.size());
