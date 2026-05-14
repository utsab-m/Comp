#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int cnt = 0;
bool vis[9][9];
string s;

void backtrack(int y, int x, int move) {
    if (y == 7 && x == 1) {
        if (move == 48) cnt++;
        return;
    }
    if (move == 48) return;

    if (vis[y][x-1] && vis[y][x+1] && !vis[y-1][x] && !vis[y+1][x]) return;
    if (vis[y-1][x] && vis[y+1][x] && !vis[y][x-1] && !vis[y][x+1]) return;

    vis[y][x] = true;

    if (s[move] == '?') {
        if (!vis[y][x+1]) backtrack(y, x+1, move+1);
        if (!vis[y][x-1]) backtrack(y, x-1, move+1);
        if (!vis[y-1][x]) backtrack(y-1, x, move+1);
        if (!vis[y+1][x]) backtrack(y+1, x, move+1);
    } else {
        int ny = y, nx = x;

        if (s[move] == 'R') nx++;
        else if (s[move] == 'L') nx--;
        else if (s[move] == 'U') ny--;
        else if (s[move] == 'D') ny++;

        if (!vis[ny][nx]) backtrack(ny, nx, move+1);
    }
    
    vis[y][x] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    
    for (int i = 0; i < 9; i++) {
        vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = true;
    }

    backtrack(1, 1, 0);

    cout << cnt << "\n";
}