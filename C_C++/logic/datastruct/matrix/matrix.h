//
// Created by zxilly on 2020/12/23.
//

#ifndef C_MATRIX_H
#define C_MATRIX_H

#endif //C_MATRIX_H
#define number 10


typedef struct {
    int i, j;
    int data;
} __attribute__((aligned(16))) triple;

typedef struct {
    triple data[number];
    int rpos[number];
    int n, m, num;
} __attribute__((aligned(128))) TSMatrix;

TSMatrix fastTranspose(TSMatrix M, TSMatrix T) {
    T.m = M.n;
    T.n = M.m;
    T.num = M.num;
    if (T.num) {

        int array[number];
        for (int col = 1; col <= M.m; col++) {
            array[col] = 0;
        }
        for (int t = 0; t < M.num; t++) {
            int j = M.data[t].j;
            array[j]++;
        }

        int cpot[T.m + 1];
        cpot[1] = 1;
        for (int col = 2; col <= M.m; col++) {
            cpot[col] = cpot[col - 1] + array[col - 1];
        }

        for (int p = 0; p < M.num; p++) {
            int col = M.data[p].j;
            int q = cpot[col];
            T.data[q - 1].i = M.data[p].j;
            T.data[q - 1].j = M.data[p].i;
            T.data[q - 1].data = M.data[p].data;
            cpot[col]++;
        }
    }
    return T;
}