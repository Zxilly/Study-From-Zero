//
// Created by 12009 on 2020/7/6.
//
#include <stdio.h>

int main() {
    int const_var = 0;
    const double locked[4] = {2.3, 2.4, 2.5, 2.6};

    const double * const pot = locked;

    for (int i = 0; i < 4; i++) {
        printf("%.1lf ", *(locked + i));
    }
}
