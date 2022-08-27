#include <new>

class Point {
    int x,y;
    Point();
    Point(int x, int y);
};

Point::Point() {
    new (this)Point(0, 0);
}

Point::Point(int _x, int _y) : x(_x), y(_y) {}
