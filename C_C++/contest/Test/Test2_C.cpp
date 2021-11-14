//
// Created by zxilly on 2021/11/7.
//

#include <iostream>

using namespace std;

int map[105][105];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            char a;
            cin >> a;
            if (a == '?') {
                map[i][j] = 0;
            } else {
                map[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == 1) {
                cout << "*";
                continue;
            }

            int point = map[i - 1][j - 1] +
                        map[i][j - 1] +
                        map[i + 1][j - 1] +
                        map[i - 1][j] +
                        map[i][j] +
                        map[i + 1][j] +
                        map[i - 1][j + 1] +
                        map[i][j + 1] +
                        map[i + 1][j + 1];
            cout << point;
        }
        cout << endl;
    }
}