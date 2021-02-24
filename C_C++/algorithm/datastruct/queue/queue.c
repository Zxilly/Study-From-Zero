//
// Created by zxilly on 2020/11/4.
//

#include "queue.h"
#include <stdio.h>

#define p(str) printf(#str);printf("\n");

int main(){
    LQueue a;
    init(&a);
    for(int i=1;i<=10;i++){
        push(&a,newNode(i));
    }
    //printf("test");
    p(获取一个队列)
    travel(&a);
    p(入队)
    for(int i=16;i<=25;i++){
        push(&a,newNode(i));
    }
    travel(&a);
    p(出队5次)
    for(int i=1;i<=5;i++){
        printf("%d\n",pop(&a)->data);
    }
    travel(&a);
    p(清空队列并入队5)
    clear(&a);
    push(&a,newNode(5));
    travel(&a);
    return 0;
}