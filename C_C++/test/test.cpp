#include <iostream>

using namespace std;

struct A
{
    short var;
    int var1;
    long var2;
    char var3;
    string s;
};

int main()
{
    short var;
    int var1;
    long var2;
    char var3;
    string s;
    A ex1;
    cout << sizeof(var) << endl;  // 2 short
    cout << sizeof(var1) << endl; // 4 int
    cout << sizeof(var2) << endl; // 8 long
    cout << sizeof(var3) << endl; // 1 char
    cout << sizeof(s) << endl;    // 8 string
    cout << sizeof(ex1) << endl;  // 32 struct
    return 0;
}