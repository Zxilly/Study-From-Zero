//
// Created by zxilly on 2020/10/15.
//


#include <stdio.h>
#include <stdlib.h>

typedef int NodeDataType;

typedef struct SListNode{
    NodeDataType data;
    struct SListNode* next;
}ListNode,*PListNode;

typedef struct PList{
    PListNode head;
}List;

ListNode newNode(NodeDataType e){
    (ListNode*)malloc(sizeof(ListNode));
    ListNode tmp;
    tmp.data=e;
    return tmp;
}


void ListInit(List *l){
    l->head=NULL;
}

void ListPushBack(List *l,NodeDataType e){
    ListNode tmp = newNode(e);

}