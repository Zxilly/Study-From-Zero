#include <stdio.h>
#include <stdlib.h>

typedef struct PNodeType
{
    int data;
    int price;
    struct PNodeType *pre;
    struct PNodeType *next;
} Node, *PNode;

int pow2(int n)
{
    //printf("get %d\n", n);
    return n * n;
}

PNode head;

PNode getNode(int data)
{
    PNode el = (PNode)malloc(sizeof(Node));
    el->pre = NULL;
    el->next = NULL;
    el->data = data;
    return el;
}

PNode getFakeNode()
{
    return getNode(0);
}

int getPrice(PNode e)
{
    int price;
    price = pow2(e->data + e->pre->data + e->next->data);
    return price;
}

int getSpecialPrice(PNode e, PNode f, PNode g)
{
    int price;
    price = pow2(e->data + f->data + g->data);
    return price;
}

int getSpecialPrice2(PNode e, PNode f)
{
    int price;
    price = pow2(e->data + f->data);
    return price;
}

int getSpecial(PNode e)
{
    int special;
    if (e->pre->pre->pre != NULL && e->next->next->next != NULL)
    {
        special = getPrice(e) + getPrice(e->pre) - getSpecialPrice(e->pre->pre, e->pre, e->next) + getPrice(e->next) - getSpecialPrice(e->pre, e->next, e->next->next);
    }
    else
    {
        special = getPrice(e) + getPrice(e->pre) - getSpecialPrice2(e->pre, e->next) + getPrice(e->next) - getSpecialPrice2(e->pre, e->next);
    }
    printf("%d's special is %d\n",e->data,special);
    return special;
}

void printList(PNode e)
{
    while (e->next->next != NULL)
    {
        printf("%d ", e->data);
        //printf("%d ",e->price);
        e = e->next;
    }
    printf("%d ", e->data);
    //printf("%d ",e->price);
}

void delNode(PNode e)
{
    e->pre->next = e->next;
    e->next->pre = e->pre;
    printf("del %d\n", e->data);
}

int length(PNode e)
{
    int count = 1;
    while (e->next->next != NULL)
    {
        count++;
        e = e->next;
    }
    return count;
}

int main()
{
    int ans = 0;
    int n = 0;
    PNode tmpPNode;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            if (i == 1)
            {
                head = getNode(tmp);
                head->pre = getFakeNode();
                head->pre->next = head;
                tmpPNode = head;
            }
            else if (i == n)
            {
                tmpPNode->next = getNode(tmp);
                tmpPNode->next->pre = tmpPNode;
                tmpPNode->next->next = getFakeNode();
                tmpPNode->next->next->pre = tmpPNode->next->next;
            }
            else
            {
                //printf("%d ",tmp);
                tmpPNode->next = getNode(tmp);
                tmpPNode->next->pre = tmpPNode;
                tmpPNode = tmpPNode->next;
            }
        }
        //printList(head);
        //printf("%d ", length(head));
        PNode currentP = head->next;
        PNode smallestP;
        while (length(head) > 2)
        {
            //printf("cal %d\n", length(head));
            int smallestData = 1000000007;
            while (1)
            {
                //printf("here\n");
                if (getSpecial(currentP) < smallestData)
                {
                    smallestP = currentP;
                    smallestData=getSpecial(smallestP);
                }
                if (currentP->next->next->next == NULL)
                {
                    currentP = head->next;
                    break;
                }
                currentP = currentP->next;
            }
            ans += getPrice(smallestP);
            printf("add %d\n",getPrice(smallestP));
            delNode(smallestP);
        }
        printf("%d\n", ans);
        printList(head);
    }
    return 0;
}