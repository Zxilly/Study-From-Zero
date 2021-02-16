//
// Created by 12009 on 2020/2/25.
//
#include <stdio.h>

int main() {
    int array[10] = {1, 2, 3, [4]=5};//指定初始化器，C专享用法

    int inital_two_dimension_array[4][4] =
            {
                    {1,  2,  3},
                    {5,  6,  7},
                    {9,  10, 11},
                    {13, 14, 15}
            };
    int inital_two_dimension_array_no[4][4] =
            {
                    1, 2, 3, 5, 6, 7, 9, 10, 12, 13, 14, 15
            };


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", inital_two_dimension_array_no[i][j]);
        }
        printf("\n");
    }
    /*
    for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
        printf("%d\n", array[i]);
    }
     */
}
