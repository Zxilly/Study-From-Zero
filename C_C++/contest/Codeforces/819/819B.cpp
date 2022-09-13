//
// Created by zxilly on 2022/9/6.
//
#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve() {
    int n;
    int m;
    cin >> n >> m;

    if (n > m) {
        cout << "No" << endl;
        return;
    }

    if (m % n == 0) {
        cout << "Yes" << endl;
        int value = m / n;
        while (n--) {
            cout << value << " ";
        }
        cout << endl;
        return;
    }

    if (m % 2 == 1 && n % 2 == 0) {
        cout << "No" << endl;
        return;
    }

    int maxcount;

    if (n % 2 == 1) {
        maxcount = 1;
    } else {
        maxcount = 2;
    }

    int onecount = n - maxcount;

    int possible_max = (m - onecount) / maxcount;
    if ((possible_max * maxcount) != (m - onecount)) {
        cout << "No" << endl;
        return;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < onecount; ++i) {
            cout << "1 ";
        }
        for (int i = 0; i < maxcount; ++i) {
            cout << possible_max << " ";
        }
        cout << endl;
        return;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}