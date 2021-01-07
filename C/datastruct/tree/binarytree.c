//
// Created by zxilly on 2021/1/6.
//

#include "binarytree.h"
#include <stdio.h>

int main(){
    PNode tree = preOrderInit();
    printf("start travel\n");
    preorderTraversal(tree);
    puts("$");
    inorderTraversal(tree);
    puts("$");
    postorderTraversal(tree);
    puts("$");
    floorTraversal(tree);
    puts("$");
    return 0;
}