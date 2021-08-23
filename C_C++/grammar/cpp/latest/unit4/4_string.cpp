//
// Created by zxilly on 2021/8/20.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    char name[200];
    cin.getline(name, 199);
    cout << name;

    string str1 = "some thing";

    string str2{"some thing"};

    string str3 = str1 + str2;

    cout << str3.size() << endl;


    wchar_t a[] = L"String";
    char16_t b[] = u"String";
    char32_t c[] = U"String";

    cout << R"(Raw String)" << endl;
    cout << R"+*(Custom RAW String)+*";
    return 0;
}