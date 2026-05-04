#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int freq[26];

bool is_possible(int n, int remaining_len) {
    int max_freq = 0;

    for (int i = 0; i < 26; i++) max_freq = max(max_freq, freq[i]);

    return max_freq <= (remaining_len + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    string res;
    bool possible = true;

    int last_char = -1;

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
        if (freq[s[i] - 'A'] > (n + 1) / 2) possible = false;
    }

    if (possible) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (j != last_char && freq[j]) {
                    freq[j]--;
                    if (is_possible(n, n - i - 1)) {
                        res += 'A' + j;
                        last_char = j;
                        goto next_char;
                    }
                    freq[j]++;
                }
            }
            next_char:;
        }
        cout << res << "\n";
    } else cout << -1 << "\n";
    
}