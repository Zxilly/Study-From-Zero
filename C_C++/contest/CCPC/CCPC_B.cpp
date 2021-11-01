//
// Created by zxilly on 2021/10/10.
//


#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        double a, b, c;
        double x0, x1, y0, y1, y2;
        cin >> a >> b >> c;
        cin >> x0 >> x1 >> y0 >> y1 >> y2;

        double p1 = (-b + sqrt(4 * a * y0 - 4 * a * c + b * b)) / 2 / a;
        double p2 = (-b - sqrt(4 * a * y0 - 4 * a * c + b * b)) / 2 / a;

        if (x0 <= p1 && p1 <= x1) {
            cout << "No" << endl;
            continue;
        }

        if ((x0 < p2 && p2 < x1)) {
            cout << "Yes" << endl;
            continue;
        } else {
            double yReady = a * x1 * x1 + b * x1 + c;
            if (y2 >= yReady && y1 <= yReady) {
                if (x1 <= p1 && p1 <= 2 * x1 - x0) {
                    cout << "No" << endl;
                    continue;
                }

                if (x1 < p2 && p2 < 2 * x1 - x0) {
                    cout << "Yes" << endl;
                    continue;
                } else {
                    cout << "No" << endl;
                    continue;
                }
            } else {
                cout << "No" << endl;
                continue;
            }
        }
    }
    return 0;
}