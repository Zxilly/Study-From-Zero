//
// Created by zxilly on 2021/8/31.
//

#include <sstream>
#include <iostream>
#include <set>
#include <iterator>

int main() {
    using namespace std;

    set<string> A{"a", "a", "b", "c"};
    ostream_iterator<string, char> out(cout, " ");
    copy(A.begin(), A.end(), out);
}