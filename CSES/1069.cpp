#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    int maxLength = 0;

    int n = s.size();

    for (int i = 0; i < n;) {
        int j = i+1;
        int length = 1;

        while (j < n && s[j] == s[i]) {
            length++;
            j++;
        }
        
        maxLength = max(maxLength, length);
        i = j;
    }

    cout << maxLength;
}