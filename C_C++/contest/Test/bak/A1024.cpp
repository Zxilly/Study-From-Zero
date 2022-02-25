//
// Created by zxilly on 2021/12/19.
//

#include <iostream>
#include <map>

// Find the string appear most, if duplicate, output in lexicographical order
int main() {
    std::map<std::string, int> map;
    int a;
    std::cin >> a;
    std::string s;
    while (std::cin >> s) {
        map[s]++;
    }
    int max = 0;
    std::string res;
    for (auto &p: map) {
        if (p.second > max) {
            max = p.second;
            res = p.first;
        } else if (p.second == max) {
            if (p.first < res) {
                res = p.first;
            }
        }
    }
    std::cout << res << std::endl;
    return 0;
}