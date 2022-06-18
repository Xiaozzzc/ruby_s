#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
#include <tuple>
#include <numeric>
#include <algorithm>

using namespace std;

// template
// typename
// typedef

// 泛型函数
template<typename T>
inline T const &Max(T const &a, T const &b) {  // inline 内联函数，编译时候会把代码直接 copy 减少函数栈的调用
    return a < b ? b : a;
}

template<typename T>
class templateTest {
public:
    void dummy() {

        int a = 1;
        int b = 2;
        cout << Max<int>(a, b) << endl;
        cout << Max(a, b) << endl;  // 亦可这样，自动推断类型

        typedef __int8_t int8_t;  // 1
        typedef __int16_t int16_t;  // 2
        typedef __int32_t int32_t;  // 4
        typedef __int64_t int64_t;  // sizeof(int64_t) = 8

        cout << sizeof(size_t) << endl;  // size_t 是一种无符号的整型数，32 位系统 size_t 4 字节，64 位系统中，size_t 是 8 字节
        cout << sizeof(__int64_t) << endl;
    }

};