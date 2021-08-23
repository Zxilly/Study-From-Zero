//
// Created by zxilly on 2021/8/22.
//

#include <iostream>

using namespace std;

int main() {
    double prices[5] = {1, 2, 3, 4, 5};
    for (double x: prices) {
        cout << x << endl;
    }

    for (double &x:prices) {
        x = x * 0.8;
    }
    for (double x: prices) {
        cout << x << endl;
    }
}