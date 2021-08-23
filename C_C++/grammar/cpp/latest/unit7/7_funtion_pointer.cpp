//
// Created by zxilly on 2021/8/23.
//

#include <iostream>

using namespace std;

int process(int a, int b, int (*func)(int, int)) {
    return func(a, b);
}

int callback(int a, int b) {
    return a + b;
}

int main() {
    cout << process(2, 4, callback);
}