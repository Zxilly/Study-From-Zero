//
// Created by 12009 on 2021/2/3.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[50] = "String";
    char a_equal[50] = "Str""ing";

    char b[] = "String"; // 这个 b 不能修改，因为它确定了字符串的位置
    char *b_equal = "String"; // 这个 b_equal 可以修改，因为字符串是另外一块内存
    // 字符串字面量不可修改


    /*while (*(b_equal)!='\0'){
        putchar(*(b_equal++));
    }
    putchar('\n');*/

    printf("%c",b_equal[2]);

    // free(b); // 字符串字面量是静态的，其地址全局唯一，不允许操作


}