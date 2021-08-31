//
// Created by zxilly on 2021/8/30.
//

#include <iostream>
#include <memory>

int main() {
    using namespace std;

    unique_ptr<double> pd(new double); // 所有权转换， 被弃用的 auto_ptr 也使用
    shared_ptr<double> pd2(new double); // 引用计数

    shared_ptr<double> pd3[2] = {
            shared_ptr<double>(new double),
            shared_ptr<double>(new double)
    };
}