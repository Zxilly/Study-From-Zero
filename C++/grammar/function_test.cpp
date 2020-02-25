//
// Created by 12009 on 2020/2/21.
//
#include <bits/stdc++.h>

void test(int a, int b) {
    printf("%d", a + b);
}

void plusone(int a) {
    printf("%d %p\n", a, &a);
    //char b[10000000000000000];
    if (a < 5)
        plusone(a + 1);

    printf("%d %p\n", a, &a);
}

int main() {
    plusone(1);
}
