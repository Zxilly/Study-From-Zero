//
// Created by zxilly on 2021/8/26.
//

class Test {
public:
    static int test;
    const static int t3 = 20; // 整形或者枚举型 const 可以在声明中被初始化
};

int Test::test = 200; // 在类方法文件中初始化静态成员。