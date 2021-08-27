#include "13_base_class.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(string fn,
                                     string ln, bool ht) : firstname(std::move(fn)),
                                                           lastname(std::move(ln)), hasTable(ht) {}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string &fn,
                         const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht) { // 列表表达式初始化父类
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) // 调用基类的复制构造函数
        : TableTennisPlayer(tp), rating(r) {
}