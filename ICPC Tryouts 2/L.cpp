#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll maxLength = 0;

struct TrieNode {
    vector<TrieNode*> chars;

    TrieNode() {
        chars.resize(26);
    }
};

struct Trie {
    TrieNode* tn;

    Trie() {
        tn = new TrieNode();
    }

    void addWord(string word) {
        int n = word.size();
        ll lengthInCommon = 0;
        TrieNode* curr = tn;
        for (int i = 0; i < n; ++i) {
            char c = word[i];
            int index = c - 'a';
            if (curr->chars[index] != nullptr) {
                ++lengthInCommon;
            } else {
                curr->chars[index] = new TrieNode();
            }
            curr = curr->chars[index];
        }
        maxLength = max(maxLength, lengthInCommon);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie* tr = new Trie();

    int n; cin >> n;

    for (int i=1; i<=n; ++i) {
        string s; cin >> s;
        tr->addWord(s);
    }

    cout << maxLength << '\n';
}