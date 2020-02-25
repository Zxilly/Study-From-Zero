//
// Created by 12009 on 2020/2/21.
//
#include <bits/stdc++.h>

int main() {
    int a;
    char name[100];
    FILE *fp;
    scanf("%s", name);
    fp = fopen(name, "r");

    if (fp == NULL) {
        printf("Cannot open\n");
        exit(1);
    }
    while ((a = getc(fp)) != EOF) {
        putchar(a);
        putchar('\n');
        printf("run once\n");
    }

    fclose(fp);
    return 0;
}
