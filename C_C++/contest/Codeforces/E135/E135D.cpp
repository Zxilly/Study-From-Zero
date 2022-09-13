//
// Created by zxilly on 2022/9/9.
//
#include <bits/stdc++.h>

using namespace std;

bool testReverse(string &s) {
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size() / 2; ++j) {
            char firstChar = s[(j + i) % s.size() - 1];
            char secondChar = s[(s.size() - 1 - j + i) % s.size()];
            if (firstChar != secondChar) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    if (testReverse(s)) {
        cout << "Draw" << endl;
    } else {
        cout << "Alice" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}