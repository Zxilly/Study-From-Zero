//
// Created by zxilly on 2022/8/30.
//
#include <bits/stdc++.h>

using namespace std;

// is upper case
bool isUpper(char c) {
    return 'A' <= c && c <= 'Z';
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int count;
        string s;
        cin >> count;
        cin >> s;
        sort(s.begin(), s.end());
        if (s.compare("Timru") == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}