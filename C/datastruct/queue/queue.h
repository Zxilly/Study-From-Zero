//
// Created by zxilly on 2020/11/4.
//

#ifndef C_QUEUE_H
#define C_QUEUE_H

#endif //C_QUEUE_H

#define DataType int

#include <stdlib.h>

typedef struct QNode{
    DataType data;
    struct QNode *next;
}QNode,*PQNode;

typedef struct LQueue{
    PQNode front;
    PQNode back;
    int size;
}LQueue;

void init(LQueue s){
    s.back=NULL;
    s.front=NULL;
    s.size=0;
}

_Bool isEmpty(LQueue s){
    return s.size==0;
}

void add(LQueue s,PQNode el){
    
}