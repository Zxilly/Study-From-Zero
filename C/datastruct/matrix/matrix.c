//
// Created by zxilly on 2020/12/23.
//

#include "matrix.h"
#include<stdio.h>

//fastTransposeMatrix放置位置
int main() {
    TSMatrix M;
    TSMatrix T;
    int datapointer = 0;

    M.m = 3;
    M.n = 2;
    M.num = 4;

    T.num = 4;

    M.data[0].i = 1;
    M.data[0].j = 2;
    M.data[0].data = 1;

    M.data[1].i = 2;
    M.data[1].j = 2;
    M.data[1].data = 3;

    M.data[2].i = 3;
    M.data[2].j = 1;
    M.data[2].data = 6;

    M.data[3].i = 3;
    M.data[3].j = 2;
    M.data[3].data = 7;

    printf("矩阵三元组表为：\n");
    for (int i = 0; i < M.num; i++) {
        printf("(%d,%d,%d)\n", M.data[i].i, M.data[i].j, M.data[i].data);
    }
    printf("矩阵为:\n");

    for (int i = 1; i <= M.m; i++) {
        for (int j = 1; j <= M.n; j++) {
            if (i == M.data[datapointer].i && j == M.data[datapointer].j) {
                printf("%d\t", M.data[datapointer].data);
                datapointer++;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }

    T = fastTranspose(M, T);
    printf("转置矩阵三元组表为：\n");
    for (int i = 0; i < T.num; i++) {
        printf("(%d,%d,%d)\n", T.data[i].i, T.data[i].j, T.data[i].data);
    }
    printf("转置矩阵为:\n");
    datapointer = 0;
    for (int i = 1; i <= T.m; i++) {
        for (int j = 1; j <= T.n; j++) {
            if (i == T.data[datapointer].i && j == T.data[datapointer].j) {
                printf("%d\t", T.data[datapointer].data);
                datapointer++;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
    return 0;
}