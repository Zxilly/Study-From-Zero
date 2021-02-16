//
// Created by 12009 on 2021/2/15.
//

#include <stdio.h>
#include <string.h>


int main() {
    char test_str[200] = "This is a test string.";
    char *addition_str = "This is additional content.";

    printf("%lu\n", strlen(test_str));

    printf("%s\n", test_str);

    strcat(test_str, addition_str);

    printf("%s\n", test_str);

}