//
// Created by zxilly on 2020/10/21.
//

#include <stdio.h>
#include "stack.h"


int main(void){
    SqStack a;
    init(&a);
    for(int i=1;i<=67;i++){
        push(&a,i);
    }
    printf("stack size is %d\n",a.stack_size);
    printf("length is %d\n",StackLength(&a));
    printf("get first is %d\n",get(&a));
    printStack(&a);
    printf("pop %d\n",pop(&a));
    printf("pop %d\n",pop(&a));
}