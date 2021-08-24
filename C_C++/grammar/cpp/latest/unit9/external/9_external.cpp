//
// Created by zxilly on 2021/8/23.
//

#include <iostream>

using namespace std;

double warming = 0.3;

extern void update(double dt);

extern void local();

int main() {
    cout << warming << endl;
    update(0.1);
    cout << warming << endl;
    local();
    return 0;
}