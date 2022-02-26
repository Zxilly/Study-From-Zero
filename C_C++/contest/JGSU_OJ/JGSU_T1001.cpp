

//
// Created by zxilly on 2022/2/25.
//

#include <iostream>

using namespace std;

const int maxN = 2 * 100000 + 10;

int f[maxN];

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

int find(int x) {
    if (x == f[x]) {
        return x;
    } else {
        f[x] = find(f[x]);
        return f[x];
    }
}

#pragma clang diagnostic pop

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        f[i] = i;
    }
    while (m--) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) {
            f[find(x)] = find(y);
        } else {
            if (find(f[x]) == find(f[y])) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}

