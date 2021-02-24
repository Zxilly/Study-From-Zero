//
// Created by zxilly on 2020/10/15.
//


#define output PrintList(&l);
#define p(str) printf(#str);printf("\n");

#define MAXN 1000000007

#include <stdio.h>
#include <stdlib.h>

typedef int NodeDataType;

typedef struct SListNode {
    NodeDataType data;
    struct SListNode *next;
} ListNode, *PListNode;

typedef struct PList {
    PListNode head;
} List, *PList;

PListNode newNode(NodeDataType e) {
    PListNode tmp = (PListNode) malloc(sizeof(ListNode));
    tmp->data = e;
    tmp->next = NULL;
    return tmp;
}


void ListInit(PList l) {
    l->head = NULL;
}

void PushBack(PList l, NodeDataType e) {
    PListNode pNewNode = newNode(e);
    //printf("%d",pNewNode->data);
    if (l->head == NULL) {
        l->head = pNewNode;
        //printf("run");
        return;
    }
    if (l->head->next) {
        PListNode pCurrentNode = l->head->next;
        while (pCurrentNode->next) {
            pCurrentNode = pCurrentNode->next;
        }
        pCurrentNode->next = pNewNode;
    } else {
        l->head->next = pNewNode;
    }
}

void PopBack(PList l) {
    if (l->head == NULL) {
        printf("Error: List is empty.Operation is not permitted.");
        return;
    } else {
        PListNode pCurrentNode = l->head;
        while (pCurrentNode->next->next) {
            pCurrentNode = pCurrentNode->next;
        }
        free(pCurrentNode->next);
        pCurrentNode->next = NULL;
    }
}

void PushFront(PList l, NodeDataType e) {
    PListNode pNewNode = newNode(e);
    if (l->head == NULL) {
        l->head = pNewNode;
        return;
    }
    pNewNode->next = l->head;
    l->head = pNewNode;
}

void PopFront(PList l) {
    if (l->head == NULL) {
        printf("Error: List is empty.Operation is not permitted.");
        return;
    }
    if (l->head->next == NULL) {
        free(l->head);
        l->head = NULL;
    } else {
        PListNode tmp = l->head;
        l->head = l->head->next;
        free(tmp);
    }
}

void InsertNode(PList l, int i, NodeDataType e) { //插入值从1开始
    int count = 1;
    PListNode perNode = l->head;
    while (perNode) {
        if (count++ == i - 1) {
            PListNode new = newNode(e);
            new->next = perNode->next;
            perNode->next = new;
            return;
        } else {
            perNode = perNode->next;
        }
    }
    printf("Error: Index out of range.\n");
}

NodeDataType DelNode(PList l, int i) {
    int count = 1;
    PListNode perNode = l->head;
    while (perNode) {
        if (count++ == i - 1) {
            PListNode tmp = perNode->next;
            NodeDataType e = perNode->next->data;
            perNode->next = perNode->next->next;
            free(tmp);
            return e;
        } else {
            perNode = perNode->next;
        }
    }
    printf("Error: Index out of range.\n");
    return MAXN;
}

void PrintList(PList l) {
    PListNode pCurrentNode = l->head;
    while (pCurrentNode) {
        printf("%-4d", pCurrentNode->data);
        if (pCurrentNode->next) {
            pCurrentNode = pCurrentNode->next;
        } else {
            break;
        }
    }
    printf("\n");
}

int isEmpty(PList l) {
    return l->head == NULL;
}

int main(void) {
    List l;
    ListInit(&l);
    for (int i = 1; i <= 10; i++) {
        PushBack(&l, i);
        //printf("%d",i);
    }
    p(尾插10个数)
    //printf("ok");
    output
    for (int i = 20; i > 10; i--) {
        PushFront(&l, i);
    }
    p(头插10个数)
    output
    PopBack(&l);
    p(尾删)
    output
    PopFront(&l);
    p(头删)
    output
    InsertNode(&l, 2, 27);
    p(在2插入27)
    output
    p(删除3并输出节点值)
    printf("%d\n", DelNode(&l, 3));
    output
    free(&l);

    List a, b;
    ListInit(&a);
    ListInit(&b);
    for (int i = 1; i <= 10; i++) {
        PushBack(&a, i);
    }
    for (int i = 6; i <= 15; i++) {
        PushBack(&b, i);
    }
    p(获得两个单链表)
    PrintList(&a);
    PrintList(&b);
    List c;
    ListInit(&c);
    while (!isEmpty(&a) && !isEmpty(&b)) {
        if (a.head->data <= b.head->data) {
            PushBack(&c, a.head->data);
            PopFront(&a);
        } else {
            PushBack(&c, b.head->data);
            PopFront(&b);
        }
    }
    if (!isEmpty(&a)) {
        while (!isEmpty(&a)) {
            PushBack(&c, a.head->data);
            PopFront(&a);
            p(test)
        }
    } else {
        while (!isEmpty(&b)) {
            PushBack(&c, b.head->data);
            PopFront(&b);
        }
    }
    p(合并后的C)
    PrintList(&c);

    return 0;
}