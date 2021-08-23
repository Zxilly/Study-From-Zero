//
// Created by zxilly on 2021/8/21.
//

#include <iostream>

using namespace std;

int main() {
    union one4all {
        int int_val;
        long long_val;
        double double_val;
    };

    one4all test{};
    test.int_val = 22;
    test.double_val = 3.0; // int_val将丢失
    cout << test.int_val << ' ' << test.double_val;

    struct widget {
        bool type;
        union {
            long id_num;
            char id_string[20];
        };
    };

    widget a = {};
    a.id_num = 20;

    struct widget2 {
        bool type;
        union ID {
            long id_num;
            char id_string[20];
        } id_val;
    };

    widget2 b = {};
    b.id_val.id_num = 20;

}