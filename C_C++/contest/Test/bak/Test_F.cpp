//
// Created by zxilly on 2021/11/6.
//

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double damage;
        double a, b, c, d;
        cin >> damage >> a >> b >> c >> d;
        cout << int(int(damage * (1 - a / 100)) + int(damage * (1 - b / 100) * 0.85) +
                    int(damage * (1 - c / 100) * 0.85 * 0.85) +
                    int(damage * (1 - d / 100) * 0.85 * 0.85 * 0.85)) << endl;
    }
    return 0;
}