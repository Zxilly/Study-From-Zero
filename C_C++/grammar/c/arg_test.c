//
// Created by 12009 on 2021/2/24.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // argument count 和 argument value

    char* ta = "32good";
    char* tb = "asdas";

    printf("%d\n",atoi(ta)); // 不安全 ,atoi 不报告错误
    printf("%d\n",atoi(tb));

    printf("%ld\n",strtol(ta,NULL,10));
    printf("%ld\n",strtol(tb,NULL,10));

    return 0;
}