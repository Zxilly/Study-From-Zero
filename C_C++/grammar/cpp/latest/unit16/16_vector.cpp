//
// Created by zxilly on 2021/8/31.
//

#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    using namespace std;

    vector<int> rating(5);
    cout << rating.size() << endl;
    auto pd = rating.begin();
    *pd = 20;
    pd++;

    vector<int> a{2, 3, 4, 5, 6};
    vector<int> b{12, 13, 14, 15, 16};
    a.insert(a.begin(), b.begin() + 1, b.end());

    cout << "Foreach" << endl;
    for_each(a.begin(), a.end(), [](int input) {
        cout << input << endl;
    });

}