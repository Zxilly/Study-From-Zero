//
// Created by zxilly on 2022/9/2.
//
#include <bits/stdc++.h>

using namespace std;


int n, k, r, c;

void draw() {
    cin >> n >> k >> r >> c;
    char shape[505][505];
    memset(shape, 0, sizeof(shape));
    int r_in_shape = r % k; // x
    int c_in_shape = c % k; // y
    for (int x = 0; x < k; x++) {
        if (x != r_in_shape && x != c_in_shape) {
            shape[x][x] = 1;
        } else {
            shape[r_in_shape][c_in_shape] = 1;
            shape[c_in_shape][r_in_shape] = 1;
        }
    }
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; ++x) {
            int ry = y % k;
            int rx = x % k;
            if (shape[ry][rx] == 1) {
                cout << "X";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }
    cout.flush();
}


int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        draw();
    }
}