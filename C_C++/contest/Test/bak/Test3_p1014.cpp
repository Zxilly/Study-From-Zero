//
// Created by zxilly on 2021/12/5.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double a, b, c;
        cin >> a >> b >> c;
        double p = (a + b + c) / 2;
        double ret = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("%.2f\n", ret);
    }
}