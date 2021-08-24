//
// Created by zxilly on 2021/8/23.
//

#include <iostream>

extern double warming;

void update(double dt);

void local();

using std::cout;

void update(double dt) {
    warming += dt;
    cout << "Update to " << warming << std::endl;
}

void local() {
    double warming = 0.42;
    cout << "Local is " << warming << std::endl;
    cout << "Global is " << ::warming << std::endl;
}