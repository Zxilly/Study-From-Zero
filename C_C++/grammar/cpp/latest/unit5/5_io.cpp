//
// Created by zxilly on 2021/8/22.
//

#include <iostream>

using namespace std;

int main() {
    char ch;
    int count = 0;
    while (cin.get(ch)) {
        cout << ch;
        ++count;
    }
    return 0;
}