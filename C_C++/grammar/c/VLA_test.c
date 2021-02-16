//
// Created by 12009 on 2021/2/3.
//

#include <stdio.h>

int test_func(int m, int n, int mn[m][n]) {
    mn[m - 1][n - 1] = 677;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mn[i][j]);
        }
        printf("\n");
    }
    return mn[m - 1][n - 1];
}

int main() {
    int m = 6;
    int n = 7;
    int mn[6][7] = {};

    printf("%d", test_func(m, n, mn));
}