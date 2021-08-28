//
// Created by zxilly on 2021/8/27.
//
#include <iostream>
#include <valarray>


int main() {
    int gpa[] = {1, 2, 3, 4, 5};
    std::valarray<int> v1;
    std::valarray<int> v2(10, 8);
    std::valarray<int> v3(gpa, 10);
    return 0;
}