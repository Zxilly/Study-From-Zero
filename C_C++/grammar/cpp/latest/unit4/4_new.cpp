//
// Created by zxilly on 2021/8/21.
//

#include <iostream>

using namespace std;

int main() {
    int *pn = new int;
    delete pn;
    char *some = new char[200];
    delete[] some;
}