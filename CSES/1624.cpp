#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll ways = 0;
vector<string> board;
unordered_map<int, int> queens;

bool same_line(double r1, double c1, double r2, double c2) {
    if (c1 == c2) return true;
    
    double slope = (r2 - r1) / (c2 - c1);
    return abs(slope) == 1;
}

bool free(int r, int c) {
    bool queenSameLine = false;
    for (int i = 0; i < r; i++) {
        if (same_line(r, c, i, queens[i])) queenSameLine = true;
    }
    return board[r][c] != '*' && !queenSameLine;
}

void backtrack(int row) {
    if (row == 8) {
        ways++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (free(row, col)) {
            queens[row] = col;
            backtrack(row+1);
            queens.erase(row);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    for (int i = 1; i <= 8; i++) {
        cin >> s;
        board.push_back(s);
    }

    backtrack(0);

    cout << ways;
}