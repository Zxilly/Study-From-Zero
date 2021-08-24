//
// Created by zxilly on 2021/8/23.
//

#include <iostream>

namespace Jack { // 默认拥有外部链接性
    double a = 20;
    int b = 42;
}

namespace Jill {
    double a;
    int b;
}

namespace Jack {
    float c; // 可以向 namespace 添加名称
}

namespace {
    int rere; // 等价于 static int rere;
}

int main() {
    std::cout << Jack::a << std::endl;
    using Jack::b;
    b = 30;
    std::cout << b << std::endl;
}