//
// Created by zxilly on 2020/10/14.
//

#include <stdio.h>

#define ListSize 100      //线性表的最大长度
typedef int DataType;

typedef struct {
    DataType data[ListSize];   //用数组存储线性表中的元素
    DataType length;           //顺序表的长度
} SeqList, *PSeqList;

void InitList(PSeqList L);  //顺序表的初始化操作
int LengthList(PSeqList L); //求顺序表的长度
int GetData(PSeqList L, int i); //返回数据表中第i个元素的值
int InsList(PSeqList L, int i, DataType e);   //在顺序表的第i个位置插入元素
int DelList(PSeqList L, DataType i, DataType *e); //删除顺序表L的第i个数据元素
int Locate(PSeqList L, DataType e); //查找数据元素e在表中的位置
void PushFront(PSeqList L, DataType e); //头插，在表头插入元素e
void PopFront(PSeqList L);    //头删,删除表中的第一个元素
void PushBack(PSeqList L, DataType e);  //尾插，在表尾插入元素e
void PopBack(PSeqList L); //尾删，删除表尾元素
void ClearList(PSeqList L);  //清空顺序表
int EmptyList(PSeqList L);   //判断顺序表是否为空
void PrintList(PSeqList L);  //打印表中元素

void InitList(PSeqList L) {
    if (L == NULL) {
        return;
    }
    L->length = 0;
}

int LengthList(PSeqList L) {
    if (L == NULL) {
        return 0;
    } else {
        return L->length;
    }
}

int GetData(PSeqList L, int i) {
    if (L->length < 1 || L->length > LengthList(L)) {
        return 0;
    } else {
        return L->data[i - 1];
    }
}

int InsList(PSeqList L, int i, DataType e) {
    if (i < 1 || L->length > LengthList(L) + 1) {
        printf("位置不合法\n");
        return 0;
    } else if (L->length >= ListSize) {
        printf("表已满\n");
        return 0;
    } else {
        for (int k = L->length; k >= i; k--) {
            //printf("%d %d %d\n", k, i, L->length);
            L->data[k] = L->data[k - 1];
        }
        L->data[i - 1] = e;
        L->length++;
        //printf("%d\n", e);
        return 1;
    }
}

int DelList(PSeqList L, DataType i, DataType *e) {
    if (L->length < 1) {
        printf("表为空！\n");
        return 0;
    }
    *e = L->data[i - 1];
    for (int k = i; k < L->length; k++) {
        L->data[k - 1] = L->data[k];
    }
    L->length--;
    return *e;
}

int Locate(PSeqList L, DataType e) {
    for (int k = 0; k < L->length; k++) {
        if (L->data[k] == e) {
            //k为e对应的数组下标，在表中对应序号应为k+1
            return k + 1;
        }
    }
    return 0;
}

void PushFront(PSeqList L, DataType e) {
    if (L->length == ListSize) {
        printf("顺序表已满，不能插入！\n");
    }
    for (int k = L->length; k > 0; k--) {
        L->data[k] = L->data[k - 1];
    }
    L->data[0] = e;
    L->length++;
}

void PopFront(PSeqList L) {
    if (EmptyList(L)) {
        printf("顺序表为空，不能插入！\n");
    }
    for (int k = 1; k <= L->length - 1; k++) {
        L->data[k - 1] = L->data[k];
    }
    L->length--;
}

void PushBack(PSeqList L, DataType e) {
    if (L->length == ListSize) {
        printf("顺序表已满，不能插入!\n");
    }
    L->data[L->length] = e;
    L->length++;
}


void PopBack(PSeqList L) {
    if (EmptyList(L)) {
        printf("表为空！\n");
    }
    L->length--;

}

void ClearList(PSeqList L) {
    L->length = 0;
}

int EmptyList(PSeqList L) {
    if (L->length == 0) {
        return 1;
    }
    return 0;
}

void PrintList(PSeqList L) {
    if (EmptyList(L)) {
        printf("表为空！\n");
        return;
    }
    for (int k = 0; k < L->length; k++) {
        printf("%-3d", L->data[k]);
    }
    printf("\n");
}

int main() {
    SeqList L;
    int data;
    InitList(&L);
    PushBack(&L, 3);
    PushBack(&L, 4);
    PushBack(&L, 5);
    PushBack(&L, 6);
    PushBack(&L, 7);
    printf("尾插5个数字 3 4 5 6 7\n");
    PrintList(&L);
    printf("在2插入5 \n");
    InsList(&L, 2, 5);
    PrintList(&L);
    printf("删除3，获取值\n");
    DelList(&L,3,&data);
    PrintList(&L);
    printf("%d\n",data);
    printf("头插 1 2 3 4 5\n");
    PushFront(&L,1);
    PushFront(&L,2);
    PushFront(&L,3);
    PushFront(&L,4);
    PushFront(&L,5);
    PrintList(&L);
    printf("定位1\n");
    PrintList(&L);
    printf("%d\n",Locate(&L,1));
    printf("头删\n");
    PopFront(&L);
    PrintList(&L);
    printf("尾删\n");
    PopBack(&L);
    PrintList(&L);
    printf("删除\n");
    ClearList(&L);
    PrintList(&L);

    SeqList M;
    InitList(&M);
    for (int i=1;i<=10;i++){
        PushBack(&L,i);
    }
    for(int i=5;i<=15;i++){
        PushBack(&M,i);
    }
    printf("生成两个顺序表\n");
    PrintList(&L);
    PrintList(&M);

    SeqList N = L;

    for (int i=1;i<=LengthList(&M);i++){
        if(!Locate(&L,GetData(&M,i))){
            PushBack(&N,GetData(&M,i));
        }
    }

    printf("去重合并\n");
    PrintList(&N);

    SeqList O;
    InitList(&O);

    while(!EmptyList(&L)&&!EmptyList(&M)){
        if(GetData(&L,1)<GetData(&M,1)){
            PushBack(&O,GetData(&L,1));
            //printf("add%d\n",GetData(&L,1));
            PopFront(&L);
        } else {
            PushBack(&O,GetData(&M,1));
            //printf("add%d\n",GetData(&M,1));
            PopFront(&M);
        }
    }

    if(!EmptyList(&L)){
        for (int i=1;i<LengthList(&L);i++){
            PushBack(&O,GetData(&L,i));
        }
    } else {
        for (int i=1;i<=LengthList(&M);i++){
            PushBack(&O,GetData(&M,i));
        }
    }

    printf("不去重合并\n");
    PrintList(&O);

    return 0;
}