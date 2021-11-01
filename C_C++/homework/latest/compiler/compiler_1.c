//
// Created by zxilly on 2021/9/18.
//

int main() {
    int a = 20;
    char tt[20];
    char t = tt[20];
    // Array index 20 is past the end of the array (which contains 20 elements)
    // 数组索引 20 越过了包含 20 个元素的数组的末端
    b = a;
    // Use of undeclared identifier 'b'
    // 使用未定义的标识符 b
    float c = a / 0;
    // Narrowing conversion from 'int' to 'float'
    // 从整形到浮点的转换属于缩小转换
    // Result of integer division used in a floating point context; possible loss of precision
    // 整形除法的结果被赋给浮点上下文，可能丢失精度
    // Division by zero is undefined
    // 除零是未定义行为

    return 0
    // Expected ';' after return statement
    // 在 return 语句后期望 ';'
}