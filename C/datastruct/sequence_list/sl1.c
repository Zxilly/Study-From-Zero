//
// Created by zxilly on 2020/10/14.
//

#include <stdio.h>

#define ListSize 100      //���Ա����󳤶�
typedef int DataType;

typedef struct {
    DataType data[ListSize];   //������洢���Ա��е�Ԫ��
    DataType length;           //˳���ĳ���
} SeqList, *PSeqList;

void InitList(PSeqList L);  //˳���ĳ�ʼ������
int LengthList(PSeqList L); //��˳���ĳ���
int GetData(PSeqList L, int i); //�������ݱ��е�i��Ԫ�ص�ֵ
int InsList(PSeqList L, int i, DataType e);   //��˳���ĵ�i��λ�ò���Ԫ��
int DelList(PSeqList L, DataType i, DataType *e); //ɾ��˳���L�ĵ�i������Ԫ��
int Locate(PSeqList L, DataType e); //��������Ԫ��e�ڱ��е�λ��
void PushFront(PSeqList L, DataType e); //ͷ�壬�ڱ�ͷ����Ԫ��e
void PopFront(PSeqList L);    //ͷɾ,ɾ�����еĵ�һ��Ԫ��
void PushBack(PSeqList L, DataType e);  //β�壬�ڱ�β����Ԫ��e
void PopBack(PSeqList L); //βɾ��ɾ����βԪ��
void ClearList(PSeqList L);  //���˳���
int EmptyList(PSeqList L);   //�ж�˳����Ƿ�Ϊ��
void PrintList(PSeqList L);  //��ӡ����Ԫ��

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
        printf("λ�ò��Ϸ�\n");
        return 0;
    } else if (L->length >= ListSize) {
        printf("������\n");
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
        printf("��Ϊ�գ�\n");
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
            //kΪe��Ӧ�������±꣬�ڱ��ж�Ӧ���ӦΪk+1
            return k + 1;
        }
    }
    return 0;
}

void PushFront(PSeqList L, DataType e) {
    if (L->length == ListSize) {
        printf("˳������������ܲ��룡\n");
    }
    for (int k = L->length; k > 0; k--) {
        L->data[k] = L->data[k - 1];
    }
    L->data[0] = e;
    L->length++;
}

void PopFront(PSeqList L) {
    if (EmptyList(L)) {
        printf("˳���Ϊ�գ����ܲ��룡\n");
    }
    for (int k = 1; k <= L->length - 1; k++) {
        L->data[k - 1] = L->data[k];
    }
    L->length--;
}

void PushBack(PSeqList L, DataType e) {
    if (L->length == ListSize) {
        printf("˳������������ܲ���!\n");
    }
    L->data[L->length] = e;
    L->length++;
}


void PopBack(PSeqList L) {
    if (EmptyList(L)) {
        printf("��Ϊ�գ�\n");
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
        printf("��Ϊ�գ�\n");
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
    printf("β��5������ 3 4 5 6 7\n");
    PrintList(&L);
    printf("��2����5 \n");
    InsList(&L, 2, 5);
    PrintList(&L);
    printf("ɾ��3����ȡֵ\n");
    DelList(&L,3,&data);
    PrintList(&L);
    printf("%d\n",data);
    printf("ͷ�� 1 2 3 4 5\n");
    PushFront(&L,1);
    PushFront(&L,2);
    PushFront(&L,3);
    PushFront(&L,4);
    PushFront(&L,5);
    PrintList(&L);
    printf("��λ1\n");
    PrintList(&L);
    printf("%d\n",Locate(&L,1));
    printf("ͷɾ\n");
    PopFront(&L);
    PrintList(&L);
    printf("βɾ\n");
    PopBack(&L);
    PrintList(&L);
    printf("ɾ��\n");
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
    printf("��������˳���\n");
    PrintList(&L);
    PrintList(&M);

    SeqList N = L;

    for (int i=1;i<=LengthList(&M);i++){
        if(!Locate(&L,GetData(&M,i))){
            PushBack(&N,GetData(&M,i));
        }
    }

    printf("ȥ�غϲ�\n");
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

    printf("��ȥ�غϲ�\n");
    PrintList(&O);

    return 0;
}