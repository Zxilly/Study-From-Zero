//
// Created by 12009 on 2020/2/25.
//
#include <stdio.h>

int main() {
    int array[10] = {1, 2, 3, [4]=5};//指定初始化器，C专享用法
    for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
        printf("%d\n", array[i]);
    }
}
