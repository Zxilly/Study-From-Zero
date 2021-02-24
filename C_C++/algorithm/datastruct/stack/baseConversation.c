//
// Created by zxilly on 2020/11/11.
//

#include "stack.h"
#include <stdio.h>

int main() {
    int input = 0;
    SqStack a;
    init(&a);
    scanf("%d",&input);
    while (input) {
        push(&a, input % 8);
        input /= 8;
    }
    while (!empty(&a)) {
        printf("%d", pop(&a));
    }
    return 0;
}