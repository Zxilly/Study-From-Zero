//
// Created by zxilly on 2021/10/18.
//

#include <iostream>

using namespace std;


int main() {
    int t, a, b1, b2, b3, b4;
    int a1, a2, a3, a4;
    int sum;
    cin >> t;
    for (int i = 0; i < t; t++) {
        cin >> a >> b1 >> b2 >> b3 >> b4;
        a1 = int(a * (1 - (b1 * 0.01)));
        a2 = int(a * (1 - (b2 * 0.01)) * 0.85);
        a3 = int(a * (1 - (b3 * 0.01)) * 0.85 * 0.85);
        a4 = int(a * (1 - (b4 * 0.01)) * 0.85 * 0.85 * 0.85);
        sum = a1 + a2 + a3 + a4;
        cout << sum << endl;
    }
    return 0;
}