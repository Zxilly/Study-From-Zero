//
// Created by zxilly on 2022/3/12.
//
#include <bits/stdc++.h>

using namespace std;

int all[5];

int main() {
    for (int &i: all) {
        cin >> i;
    }
    int ans = 0;
    for (int &i: all) {
        int a = i / 1000;
        int b = i % 1000 / 100;
        int c = i % 100 / 10;
        int d = i % 10;
        if (a == c && d - b == 1) {
            ans++;
        }
    }
    cout << ans << endl;
}
