//
// Created by zxilly on 2021/8/27.
//

class Test {
private:
    static int flag;
public:
    static void setFlag() {
        Test::flag = 30;
    }
};

int Test::flag = 20;