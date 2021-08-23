//
// Created by zxilly on 2021/8/23.
//

#include <iostream>

using namespace std;

int main() {
    int sloth = 3;
    const int *ps = &sloth; // const pointer value
    int *const finger = &sloth; // const pointer address
}