//
// Created by zxilly on 2020/10/21.
//

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define STACK_INCREMENT 20

typedef int DataType;

typedef struct{
    DataType *base;
    DataType *top;
    int stack_size;
}SqStack,*PSqStack;

void init(PSqStack s){
    s->base = (DataType*)malloc(STACK_SIZE*sizeof(DataType));
    s->top = s->base;
    s->stack_size = STACK_SIZE;
}

void push(PSqStack s,DataType e){
    if(s->top-s->base>=s->stack_size){
        s->base = (DataType*)realloc(s->base,(s->stack_size+STACK_INCREMENT)*sizeof(DataType));
        s->top = s->base+s->stack_size;
    }
    *s->top = e;
    s->top++;
}

DataType pop(PSqStack s){
    if(s->top==s->base){
        return -1;
    } else {
        DataType e = *(s->top-1);
        s->top--;
        return e;
    }
}

_Bool empty(PSqStack s){
    return s->top==s->base;
}

void clear(PSqStack s){
    while(!empty(s)){
        pop(s);
    }
}

void destroy(PSqStack s){
    free(s->base);
}

DataType get(PSqStack s){
    if(empty(s)){
        return -1;
    } else {
        return *(s->top-1);
    }
}

void print(PSqStack s){

}

DataType StackLength(PSqStack s){
    return s->top-s->base;
}



int main(void){
    SqStack a;
    init(&a);
    push(&a,3);
    push(&a,4);
    printf("%d\n",StackLength(&a));
    printf("%d\n",get(&a));
    printf("%d\n",pop(&a));
    printf("%d\n",pop(&a));
}