//
// Created by zxilly on 2022/9/2.
//
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int ay[maxn];
int by[maxn];

void solve() {
    ay[0] = -1;
    by[0] = -1;
    int bigA = -1;
    int smallB = 1e9 + 5;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> ay[i];
        if (ay[i] > bigA) {
            bigA = ay[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> by[i];
        if (by[i] < smallB) {
            smallB = by[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int val = by[i] - ay[i];
        if (val < 0) {
            cout << "NO" << endl;
            return;
        }
    }
//    if (bigA <= smallB) {
//
//    } else {
//
//    }
    for (int i = 1; i < n; ++i) {
        if (by[i] > (by[i + 1] + 1) && by[i] - ay[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    if (by[n] > (by[1] + 1) && by[n] - ay[n] != 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}