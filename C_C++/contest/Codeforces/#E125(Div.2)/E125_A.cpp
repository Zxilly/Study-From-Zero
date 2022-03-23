//
// Created by zxilly on 2022/3/23.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            cout << 0 << "\n";
            continue;
        }
        int ret = sqrt(x * x + y * y);
        if (ret * ret == x * x + y * y) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
        cout << flush;
    }
    return 0;
}