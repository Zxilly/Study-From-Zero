//
// Created by zxilly on 2021/4/6.
//

#include <stdio.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
void count(){
    static int count;
    count++;
    printf("%d\n",count);
}

void fakecount(){
    int count;
    count++;
    printf("%d\n",count);
}

int main(){
    for (int i = 0; i < 100; ++i) {
        count();
        fakecount();
    }
}
#pragma clang diagnostic pop