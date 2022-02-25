//
// Created by zxilly on 2021/10/18.
//

#include <time.h>

int main() {
    long long a = 9223372036854775800;
    struct tm *tm = gmtime(&a);
}