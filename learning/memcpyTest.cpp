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


void memTest() {
    vector<int> dist = {0, 1, 6, 8};
    vector<int> speed = {2, 2, 3, 3, 4, 4, 4, 4, 4};

    vector<int> res;
    // resize(10) 表示把数组的长度重新设置为 10（不是大小变为 10 字节）
    res.resize(13);
    // res.data() + 1，这里的 1 是 一个 vector 元素，而不是一个字节
    // dist.data() 表示 vector<int> dist 的起始位置
    // dist.size() * sizeof(int) 表示字节长度

    merge(dist.begin(), dist.begin() + 4, speed.begin(), speed.end(), res.begin());

    cout << res[0] << endl;
    // memcpy(res.data() + 1, dist.data(), dist.size() * sizeof(int));
}