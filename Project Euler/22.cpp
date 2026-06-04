#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int get_score(string s) {
    int score = 0;

    for (char c: s) if (c != '\"') score += c - 'A' + 1;

    return score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("22.txt");

    vector<string> names;

    string name;

    while (getline(file, name, ',')) {
        names.push_back(name);
    }

    sort(names.begin(), names.end());

    ll totalScore = 0;

    for (int i = 0; i < names.size(); i++) {
        string name = names[i];
        int score = get_score(name);

        totalScore += score * (i+1);
        
    }

    cout << totalScore << "\n";
}