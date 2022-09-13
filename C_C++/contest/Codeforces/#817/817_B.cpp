//
// Created by zxilly on 2022/8/30.
//
#include <bits/stdc++.h>

using namespace std;

bool isSame(string a, string b, int count) {
    for (int i = 0; i < count; ++i) {
        char ca = a[i];
        char cb = b[i];
        if (ca == 'G') {
            ca = 'B';
        }
        if (cb == 'G') {
            cb = 'B';
        }
        if (ca != cb) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string a;
        string b;
        int count;
        cin >> count;
        cin >> a;
        cin >> b;
        if (isSame(a, b, count)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}