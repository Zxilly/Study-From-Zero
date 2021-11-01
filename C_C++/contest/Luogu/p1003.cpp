//
// Created by zxilly on 2021/10/21.
//

#include <iostream>

using namespace std;

int carpets[10005][4];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        carpets[i][0] = a;
        carpets[i][1] = b;
        carpets[i][2] = a + x;
        carpets[i][3] = b + y;
    }
    int x, y, result = -1;
    cin >> x >> y;
    for (int i = 0; i < n; ++i) {
        int a = carpets[i][0];
        int b = carpets[i][1];
        int c = carpets[i][2];
        int d = carpets[i][3];
        if ((a <= x && x <= c) && (b <= y && y <= d)) {
            result = i + 1;
        }
    }
    cout << result << endl;
    return 0;
}