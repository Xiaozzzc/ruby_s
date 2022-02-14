#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <tuple>
#include <numeric>
#include <algorithm>

using namespace std;

namespace ruby {
    namespace luo {

        void luoFunc() {
            static int i = 10;  // 仅在第一次定义时候设置 i = 10
            i++;
            cout << i << endl;
        }
    }
}

namespace ruby {
    namespace luo {
        void testFun2() {

        }
    }
}

void luoTest() {
    using namespace ruby::luo;
    luoFunc();
    ruby::luo::luoFunc();
    ruby::luo::luoFunc();
    ruby::luo::luoFunc();
    ruby::luo::luoFunc();
    ruby::luo::testFun2();
    vector<int> arr = {1, 2, 3, 4, 5};
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        cout << *it << endl;
    }
}
