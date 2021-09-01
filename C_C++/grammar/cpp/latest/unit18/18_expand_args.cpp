//
// Created by zxilly on 2021/9/1.
//

#include <iostream>

using namespace std;

void show() {

}

template<typename T, typename ...Args>
void show(T value, Args... args) {
    cout << value << endl;
    show(args...);
}

int main() {
    show(2, 3, 4, "sada", (double) 200);
}