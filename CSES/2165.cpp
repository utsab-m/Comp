#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> moves;

void backtrack(int n, int A, int B, int C) {
    if (n > 0) {
        backtrack(n-1, A, C, B);
        moves.push_back(to_string(A) + " " + to_string(C));
        backtrack(n-1, B, A, C);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    backtrack(n, 1, 2, 3);
    cout << moves.size() << "\n";

    for (string move: moves) cout << move << "\n";
}