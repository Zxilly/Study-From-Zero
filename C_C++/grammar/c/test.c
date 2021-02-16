//
// Created by 12009 on 2021/2/15.
//

#include <stdio.h>
#include <string.h>

int main() {
    char *key = "ABC";
    char ready[20] = {0};

    scanf("%s", ready);

    if (!strcmp(key, ready)) {
        printf("OK");
    }
}