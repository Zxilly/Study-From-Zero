//
// Created by zxilly on 2021/8/24.
//

class Test {
public:
    Test();

    ~Test();

    int *p;

private:

};

Test::Test() {
    this->p = new int[20];
}

Test::~Test() {
    delete[] this->p;
}

void test() {
    Test test1;
}

int main() {
    test();
}