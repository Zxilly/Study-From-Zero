//
// Created by 12009 on 2021/2/3.
//

#include <stdio.h>

int print(int arr[], int n) { // 等价于 int *arr 第一个 [] 指示当前变量为指针
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}

int main() {
    int a[6] = {1, 2, 3, 4, 5, 6};
    print(a, 6);
}