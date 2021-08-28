//
// Created by zxilly on 2021/8/28.
//

#include <iostream>

template<class T = int, int init = 30> // 可以为类模板类型提供默认值
class Test {
private:
    T items[10] = {init};
public:
    Test();
};

template<class T, int init>
Test<T, init>::Test() {
    items[9] = init;
}

template<typename T = double, T init = 60>
// 可以为函数模板参数提供默认值
T test2() {
    return 20 + init;
}

int main() {
    Test<int, 50> a;
    std::cout << test2<int, 30>();
    return 0;
}