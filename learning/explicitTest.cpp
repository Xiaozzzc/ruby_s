#include <iostream>


using namespace std;

class Point {
public:
    int x, y;

    // 构造函数不加 explicit，允许"构造函数的隐式转换"
    Point(int x = 0, int y = 0)
            : x(x), y(y) {}

    // 构造函数加 explicit，不允许构造函数的隐式转换
//    explicit Point(int x = 0, int y = 0)
//            : x(x), y(y) {}
};

void displayPoint(const Point &p) {
    cout << "(" << p.x << ","
         << p.y << ")" << endl;
}

void dummy() {
    displayPoint(1);
    Point p1 = 2;

#define CREATE_FOR_TYPE(TYPE)
    CREATE_FOR_TYPE(UInt8)
    CREATE_FOR_TYPE(UInt16)
#undef CREATE_FOR_TYPE
}