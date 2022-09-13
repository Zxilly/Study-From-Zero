//
// Created by zxilly on 2022/9/12.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int dist_a = a - 1;
    int dist_b = abs(c - b) + c - 1;
    if (dist_a < dist_b) {
        cout << 1 << endl;
    } else if (dist_a > dist_b) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}