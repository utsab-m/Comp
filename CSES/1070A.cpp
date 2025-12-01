#include "bits/stdc++.h"
#include <unordered_set>
using namespace std;

void print(vector<int>& res) {
    if (res.empty()) {
        cout << "NO SOLUTION";
    } else {
        for (int num: res) {
            cout << num << " ";
        }
    }
};

bool backtrack(vector<int>& res, long n, unordered_set<int>& seen) {
    if (res.size() == n) {
        print(res);
        return true;
    }
    for (int i = 1; i <= n; i++) {
        if (seen.find(i) == seen.end() && ((res.size() > 0 && abs(i - res[res.size() - 1]) > 1) || res.size() == 0)) {
            res.push_back(i);
            seen.insert(i);
            if (backtrack(res, n, seen)) return true;
            seen.erase(i);
            res.pop_back();
        } 
    }
    return false;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long n;
    cin >> n;
    
    vector<int> res;
    unordered_set<int> seen;

    if (!backtrack(res, n, seen)) print(res);
}

