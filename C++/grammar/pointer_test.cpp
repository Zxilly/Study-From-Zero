//
// Created by 12009 on 2020/2/22.
//
#include <cstdio>

using namespace std;

int changenum(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 5, b = 3;
    changenum(&a, &b);

    int *pi, *pt;
    char *pc;
    float *pf, *pg;

    int array[20];

    //printf("%d %d", a, b);
    printf("%d",array==&array[0]);
}
