//
// Created by zxilly on 2021/8/25.
//

#include <iostream>

using namespace std;

class Test {
private:
    enum Err {
        A, B, C, D
    }; // 不会出现在被初始化的实例中
    static const int Months = 12; // 以上都是静态的，可以被所有实例共享
};

int main() {

}