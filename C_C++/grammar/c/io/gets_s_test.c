//
// Created by 12009 on 2021/2/14.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    char words[10] = {};

    gets_s(words, 15);

    for (int i = 0; i < 5; ++i) {
        putchar(words[i]);
    }
}