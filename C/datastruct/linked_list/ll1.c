//
// Created by zxilly on 2020/10/15.
//


#include <stdio.h>
#include <stdlib.h>

typedef int NodeDataType;

typedef struct SListNode {
    NodeDataType data;
    struct SListNode *next;
} ListNode, *PListNode;

typedef struct PList {
    PListNode head;
} List;

PListNode newNode(NodeDataType e) {
    PListNode tmp = (PListNode) malloc(sizeof(PListNode));
    tmp->data = e;
    tmp->next = NULL;
    return tmp;
}


void ListInit(List *l) {
    l->head = NULL;
}

void PushBack(List l, NodeDataType e) {
    PListNode pNewNode = newNode(e);
    if (l.head == NULL) {
        l.head = pNewNode;
        return;
    }
    PListNode pCurrentNode = l.head->next;
    while (pCurrentNode->next) {
        pCurrentNode = pCurrentNode->next;
    }
    pCurrentNode->next = pNewNode;

}

void PopBack(List l) {
    if (l.head == NULL) {
        printf("Error: List is empty.Operation is not permitted.");
        return;
    }
    PListNode pCurrentNode = l.head;
    while (pCurrentNode->next) {
        pCurrentNode = pCurrentNode->next;
    }
    free(pCurrentNode->next);
    pCurrentNode->next = NULL;
}

void PushFront(List l, NodeDataType e) {
    PListNode pNewNode = newNode(e);
    if (l.head == NULL) {
        l.head = pNewNode;
        return;
    }
    pNewNode->next = l.head;
    l.head = pNewNode;
}

void PopFront(List l) {
    if (l.head == NULL) {
        printf("Error: List is empty.Operation is not permitted.");
        return;
    }
    if (l.head->next == NULL) {
        free(l.head);
        l.head = NULL;
    } else {
        PListNode tmp = l.head;
        l.head=l.head->next;
        free(tmp);
    }
}

void InsertNode(List l,int i,NodeDataType e){ //插入值从1开始
    int count=0;
    PListNode preNode = l.head;
    while(preNode){
        if(count++==i-1){
            break;
        } else {
            preNode = preNode->next;
        }
    }

}

void PrintList(List l) {
    PListNode pCurrentNode = l.head;
    printf("%d",pCurrentNode->data);
    while (pCurrentNode) {
        printf("%d\t", pCurrentNode->data);
        if (pCurrentNode->next) {
            pCurrentNode = pCurrentNode->next;
        } else {
            break;
        }
    }
}

int main(void){
    List l;
    ListInit(&l);
    for(int i=1;i<=10;i++){
        PushBack(l,i);
        //printf("%d",i);
    }
    printf("ok");
    PrintList(l);
}