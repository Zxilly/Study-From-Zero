//
// Created by zxilly on 2021/1/6.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef C_BINARYTREE_H
#define C_BINARYTREE_H

#endif //C_BINARYTREE_H


typedef struct LeafNode {
    int data; // 数据
    struct LeafNode *left; // 左边叶子的指针
    struct LeafNode *right; // 右边叶子的指针
} __attribute__((aligned(32))) __attribute__((packed)) Node,*PNode;

PNode createNode() {
    Node *tNode = (PNode)malloc(sizeof(Node));
    int data;
    scanf("%d",&data);
    // printf("gets %d\n",data);
    if (data==-1){
        return NULL;
    }
    tNode->data = data;
    tNode->left = createNode();
    tNode->right = createNode();
    return tNode;
}

PNode preOrderInit(){
    PNode tree = createNode();
    return tree;
}

void preorderTraversal(Node *nd) {
    if (nd == NULL)
        return;
    printf("%d ", nd->data);
    preorderTraversal(nd->left);
    preorderTraversal(nd->right);
}

void inorderTraversal(Node *nd) {
    if (nd == NULL)
        return;
    inorderTraversal(nd->left);
    printf("%d ", nd->data);
    inorderTraversal(nd->right);
}

void postorderTraversal(Node *nd) {
    if (nd == NULL)
        return;
    postorderTraversal(nd->left);
    postorderTraversal(nd->right);
    printf("%d ", nd->data);
}

void floorTraversal(PNode Tree)
{
    PNode temp[100];
    int in = 0;
    int out = 0;

    temp[in++] = Tree;  //先保存二叉树根节点

    while (in > out)
    {
        if (temp[out])
        {
            printf("%d ",temp[out]->data);
            temp[in++] = temp[out]->left;
            temp[in++] = temp[out]->right;
        }
        out++;
    }
}