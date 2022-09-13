//
// Created by zxilly on 2022/9/7.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (n > m) {
        cout << "No" << endl;
        return;
    }

    if (m % n == 0) {
        cout << "Yes" << endl;
        int out = m / n;
        for (int i = 0; i < n; ++i) {
            cout << out << " ";
        }
        cout << "\n";
        return;
    }

    if ((m % 2) != (n % 2)) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    int out = m / n;

    if (m % 2 == 1) {
        for (int i = 0; i < n - i; ++i) {
            cout << out << " ";
        }
        cout << m - (n - 1) * out;
    } else {
        for (int i = 0; i < n - 2; ++i) {
            cout << out << " ";
        }
        cout << (m - (n - 2) * out) / 2;
        cout << " ";
        cout << (m - (n - 2) * out) / 2;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}