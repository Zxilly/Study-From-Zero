//
// Created by zxilly on 2021/8/24.
//

#include <iostream>

class Line {
private:
    int length;
    int width;
    int height;
public:
    Line(int len, int wid, int hei);
};

Line::Line(int len, int wid, int hei) : length(len), width(wid), height(hei) {}
