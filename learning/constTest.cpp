#include "iostream"

using namespace std;


void constTest() {
    // const 是 constant 的缩写，意为不变的量
    const int m = 8;
    int *p = (int *) &m;
    *p = 9;
    cout << m << endl;  // 8

    int a = 8;
    int *const p2 = &a;  // 指向的地址不能变
    *p2 = 9; // 正确
    int b = 7;
    // p2 = &b; // 错误


    const int *p3 = &a;
    // *p3 = 889; —— 错误，int 变量 *p3 是不可变的
    int *const p4 = &a;
    // p4 = &mp; —— 错误 int* 类型变量 p4 是不可变的
}