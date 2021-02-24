//
// Created by zxilly on 2020/12/9.
//

#include "string.h"
#include <stdio.h>

int main(){
    string hs;
    initstring(&hs);
    createstring(&hs,"teststrone");
    printstring(&hs);
    string hs2;
    initstring(&hs2);
    createstring(&hs2,"teststrtwo");
    printstring(&hs2);
    int compare = stringcompare(hs,hs2);
    printf("compare = %d\n",compare);
    string t;
    initstring(&t);
    stringconnection(&t,hs,hs2);
    printstring(&t);
    printstring(&hs);
    stringsub(&t,hs,5,9);
    printstring(&t);
    int index = stringindex(hs, t, 4);
    printf("%d\n",index);
    return 0;
}
