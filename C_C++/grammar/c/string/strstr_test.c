//
// Created by 12009 on 2021/2/24.
//

#include <stdio.h>
#include <string.h>


int main()
{
    const char haystack[20] = "TESTA";
    const char needle[10] = "ST";
    char *ret;

    ret = strstr(haystack, needle);

    printf("子字符串index至结束： %s\n", ret);

    return(0);
}
