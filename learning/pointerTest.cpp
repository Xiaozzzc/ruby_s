#include "iostream"

using namespace std;

void pointerTest() {
    // &
    // 取变量地址 &a
    // 表引用 void pointerTest(vector<int>& vec) {...}
    //
    // *
    // 代表指针 int*
    // 取指针变量指向的值 *pt
    int a = 8;
    int *pt = &a;
    int b = *pt;

    *pt = 9;

    cout << a << endl;  // 9
    cout << b << endl;  // 8
}