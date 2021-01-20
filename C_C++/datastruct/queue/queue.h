//
// Created by zxilly on 2020/11/4.
//

#ifndef C_QUEUE_H
#define C_QUEUE_H

#endif //C_QUEUE_H

#define DataType int

#include <stdlib.h>
#include <stdio.h>

typedef struct QNode {
    DataType data;
    struct QNode *next;
} QNode, *PQNode;

typedef struct LQueue {
    PQNode front;
    PQNode back;
    int size;
} LQueue, *PLQueue;

void init(PLQueue s) {
    s->back = NULL;
    s->front = NULL;
    s->size = 0;
}

int isEmpty(PLQueue s) {
    return s->size == 0;
}

PQNode newNode(DataType e) {
    PQNode tmp = (PQNode) malloc(sizeof(QNode));
    tmp->data = e;
    tmp->next = NULL;
    return tmp;
}

void push(PLQueue s, PQNode el) {
    if (s->front == NULL && s->back == NULL) {
        s->front = s->back = el;
    } else {
        s->back->next = el;
        s->back = el;
    }
    s->size++;
}

PQNode pop(PLQueue s) {
    PQNode tmp = s->front;
    if(s->size>1){
        s->front = s->front->next;
        s->size--;
    } else {
        s->front = s->back = NULL;
        s->size--;
    }
    return tmp;
}

void clear(PLQueue s) {
    while(!isEmpty(s)){
        free(pop(s));
    }
}

void destory(PLQueue s){
    clear(s);
    free(s);
}

void travel(PLQueue s) {
    PQNode tmp = s->front;
    while (tmp) {
        printf("%-4d", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}




