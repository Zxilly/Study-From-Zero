//
// Created by zxilly on 2020/11/13.
//

#include <cstdio>

using namespace std;

void customSwap(int &a,int &b){
    int c;
    c = a;
    a = b;
    b = c;
}

int main(){
    int a=1,b=2;
    printf("%d %d\n",a,b);
    customSwap(a,b);
    printf("%d %d\n",a,b);
    return 0;
}