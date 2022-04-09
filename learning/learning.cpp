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

class Learning {

public:

    /*
     * vector -> push_back(), find()
     * set -> insert(), erase(), find()
     * map -> insert(pair<int, string>()), find()
     * stack -> push(), pop(), top(), empty()
     * queue -> push(), pop(), front(), back(), empty()
     */
    void stringTest() {
        string s = "abc";
        string s1 = "hello";
        string s2 = "hello world";
        string s3;  // ""
        char c;  // \0
        char c1 = 'a';
        s += s1 + s2;
        s3 += c1;

        // 比较，小于 0 表示s1小；等于 0 表示相等
        int cmp = s1.compare(s2);

        // 交换两个字符串
        s1.swap(s2);

        // 查找
        int n = s.find("hel");  // 返回第一次找到的下标
        int n1 = s.rfind("hel");  // 从后往前，返回第一次找到的下标

        if (s.find('u') != string::npos) {
        }

        if (s.find('u', 3) != string::npos) {  // 从下标3开始查找
        }

        // 取子串
        string sub = s.substr(1, 2);

        // 删除
        s1.erase(1, 3);  // 删除 从下标1开始，长度为3的子串

        // 反转
        reverse(s.begin(), s.end());

        // startWith
        if (s1.find(s2) == 0) {
        }

        // endWith
        if (s1.find(s2) == s1.size() - s2.size()) {
        }
    }

    void vecTest() {
        vector<int> init;
        // init[10] = 9;  会报错，因为根本没有分配空间
        vector<int> left(10);  // 定义大小为 10 的vector，初始值为 0
        vector<int> right(10, 20);  // 定义大小为 10 的vector，初始值为 20

        iota(left.begin(), left.end(), 10);  // 10, 11, 12 ...
        int sum = accumulate(left.begin(), left.end(), 0);  // 将left中的元素累加，累加初始值为 0
        cout << sum << endl;

        left[100] = 100;  // 不会报错，见下面 num[100] = 250
        for (vector<int>::iterator it = left.begin(); it != left.end(); it++) {
            cout << *it << endl;
        }

        int rightSize = right.size();
        right.push_back(10);
        int newRightSize = right.size();

        vector<int> u{1, 2, 3, 4, 5};
        vector<int> num = {2, 4, 5, 1, 3, 6};
        num.insert(num.end(), 5, 4);  // 在 num 的最后面添加 5 个 4

        int t0 = num[100];  // t0 = 0, 不会报错
        num[100] = 250;  // 不会报错
        int q = num[100];  // 250
        int t1 = num[100];  // t1 = 250
        int t2 = num.size();  // t2 = 11

        // 将 vector 从小到大排序
        sort(num.begin(), num.end());

        // 将 vector 从大到小排序
        sort(num.begin(), num.end(), [](int a, int b) { return a > b; });

        int n = num.size();
        for (int i = 0; i < n; i++) {
            cout << num[i] << endl;
        }

        for (int x: num) {
            cout << x << endl;
        }

        // 二维 vector
        vector<vector<int>> graph;
        vector<int> a = {1, 2, 3, 4};
        vector<int> b = {5, 6, 7};

        // 直接构建二维 vector
        graph = {a, b};
        for (auto &x: graph) {
            for (auto q: x) {
                cout << q << endl;
            }
        }
    }

    void mapTest() {
        map<int, string> mp;  // map中的元素是自动按Key升序排序，跟set一样
        mp[1] = "2";
        mp[2] = "3";
        mp[3] = "4";
        mp[4] = "5";
        mp.insert(pair<int, string>(5, "6"));  // 这样插入元素
        // map 结构是由一个个 pair<> 组织的

        string string1 = mp[6];  // 空字符串 ""

        map<int, int> mp1;
        mp1[1]++;  // mp1 中有一个元素 pair<int, string>(1, 1)，即 1 -> 1
        // map 值返回的是 指针

        string tmp = mp[100];  // 不会报错，会为""

        cout << "size:" << mp.size() << endl;

        // map本身就是按key排序，自有序
        // 通过map对象的方法获取的 iterator 数据类型是一个 std::pair 对象
        // 包括两个数据 iterator -> first和 iterator -> second 分别代表 关键字 和 存储的数据
        map<int, string>::iterator iter1 = mp.lower_bound(1);  // 1, "2"
        map<int, string>::iterator iter2 = mp.upper_bound(1);  // 2, "3"
        map<int, string>::iterator iter3 = mp.find(1);  // 1, "2"
        cout << iter1->second << endl;

        // map删除元素
        bool b = mp.erase(1);
        if (b) {
            cout << "删除了" << endl;
        }

        // 判断是否包含元素
        if (mp.find(1) == mp.end()) {
            cout << "不包含该元素" << endl;
        }

        // 遍历
        for (map<int, string>::iterator it = mp.begin(); it != mp.end(); it++) {
            cout << it->second << endl;
        }

        // 遍历方式 2
        for (auto&[k, v]: mp) {
            cout << k << endl;
            cout << v << endl;
        }

        // 判断是否为空
        bool b1 = mp.empty();
        if (b1) {
            cout << "map 为空" << endl;
        }
    }

    void setTest() {
        int arr[5] = {0, 1, 2, 3, 4};
        set<int> iSet(arr, arr + 5);  // 由数组初始化 set
        set<int> emptySet;  // 定义空 set

        // 添加元素
        iSet.insert(3);
        iSet.insert(3);
        iSet.insert(5);
        // emplace 比 insert 快
        iSet.emplace(8);
        iSet.emplace(9);

        cout << "size:" << iSet.size() << endl;
        cout << "3 count = " << iSet.count(3) << endl;  // set.count(x) 只能返回0或1；可用来判断元素是否存在过

        iSet.erase(1);  // 删除元素

        // 遍历 1
        set<int>::iterator it1 = iSet.begin();
        set<int>::iterator it2 = iSet.end();
        for (; it1 != it2; it1++) {  // 遍历；所有元素都会根据元素的键值自动排序
            cout << *it1;
        }
        cout << endl;

        // 遍历 2
        for (auto &u: iSet) {
            // ...
            cout << u << endl;
        }

        // 查找
        int n1 = iSet.count(3);  // set.count(x) 只能返回0或1；可用来判断元素是否存在过
        if (n1 == 0) {
            cout << "3 not found" << endl;
        }
        it1 = iSet.find(3);
        if (it1 != iSet.end())  // set 中是否存在元素
            cout << "3 found" << endl;

        it1 = iSet.find(1);
        if (it1 != iSet.end())
            cout << "1 not found" << endl;

        iSet.clear();
    }

    void stackTest() {
        stack<int> stack; // 定义stack
        stack.push(1);  // 添加元素
        if (!stack.empty()) {  // 判空
            int top = stack.top();  // 取栈顶
            cout << top << endl;
            stack.pop();
        }
    }

    void queueTest() {
        queue<string> queue;  // 定义queue
        queue.push("3");  // 添加元素
        if (!queue.empty()) {  // 判空
            string front = queue.front();  // 取最前元素
            string back = queue.back();
            queue.pop();
        }
    }

    void priorityQueueTest() {
        // 默认大顶堆；等同于 priority_queue<int, vector<int>, less<int> > a;
        priority_queue<int> a;
        priority_queue<int, vector<int>, greater<int> > c;  // 这样就是小顶堆

        priority_queue<string> b;

        for (int i = 0; i < 5; i++) {
            a.push(i);
            c.push(i);
        }

        while (!a.empty()) {
            cout << a.top() << ' ';
            a.pop();
        }
        cout << endl;

        while (!c.empty()) {
            cout << c.top() << ' ';
            c.pop();
        }
        cout << endl;

        b.push("abc");
        b.push("abcd");
        b.push("cbd");
        while (!b.empty()) {
            cout << b.top() << ' ';
            b.pop();
        }
        cout << endl;
    }
};