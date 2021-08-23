//
// Created by zxilly on 2021/8/21.
//

#include <iostream>

using namespace std;

enum fruit {
    red, green, orange
};

enum bits {
    one = 1,
    two = 2,
    four = 4,
    eight = 8
};

int main() {
    fruit a = red;
    bits flag = bits(6);
    cout << int(flag);
}