//
// Created by zxilly on 2022/9/13.
//
#include <bits/stdc++.h>

using namespace std;


signed main() {
    std::ios::sync_with_stdio(false);
    int limit = 50;
    pair<long long, long long> ans_pair = make_pair(-1, -1);
    for (int i = 2; i < limit + 2; ++i) {
        long long ret1, ret2;
        cout << "? " << i << " " << 1 << endl;
        cin >> ret1;
        cout << "? " << 1 << " " << i << endl;
        cin >> ret2;
        if (ret1 == -1) {
            cout << "! " << i - 1 << endl;
        } else if (ret1 != ret2) {
            cout << "! " << ret1 + ret2 << endl;
        }
    }

    return 0;
}