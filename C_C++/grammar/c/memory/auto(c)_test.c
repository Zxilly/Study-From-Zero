//
// Created by zxilly on 2021/4/6.
//

#include <stdio.h>

int main() {
    int i = 400; // 直接定义就是auto，auto仅表示显式定义
    for (auto int i = 0; i < 20; ++i) {
        printf("%d\n", i);
    }
    printf("%d\n", i);
}