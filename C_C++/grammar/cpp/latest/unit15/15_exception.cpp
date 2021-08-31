//
// Created by zxilly on 2021/8/29.
//

#include <iostream>

using namespace std;

class err : public exception {
public:
    const char *what() const noexcept override;
};

const char *err::what() const noexcept {
    return "What the hell is happening!";
}

void manual_exception_handler() {
    std::cout << "unCatch Exception" << std::endl;
}

int main() {
    set_terminate(manual_exception_handler);

    try {
        throw "Throw a String";
    } catch (const char *err) {
        cout << err << endl;
    }

    try {
        throw 200;
    } catch (...) {
        cout << "Catch any exception like" << endl;
    }

    try {
        throw err();
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    struct Big {
        double stuff[200000000];
    };

    throw "Error";

    Big *pb;
    try {
        pb = new Big[1000000000];
    } catch (bad_alloc &ba) {
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
}