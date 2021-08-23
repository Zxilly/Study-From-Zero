//
// Created by zxilly on 2021/8/23.
//

#include <iostream>
#include <cstring>

using namespace std;

const int array_size = 10;

int sum_array(const int arr[], int n);
char *get_str(int length, char fill);

int main() {
    int cookies[array_size] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = sum_array(cookies, 3);
    int sum2 = sum_array(cookies + 3, 3);
    char *str = get_str(3,'F');
    std::cout << sum << ' ' << sum2 << endl;
    std::cout << str;
    delete[] str;
}

int sum_array(const int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += arr[i];
    }
    return count;
}

char *get_str(int length, char fill) {
    char *ptr = new char[length + 1];
    memset(ptr, fill, length + 1);
    ptr[length] = '\0';
    return ptr;
}