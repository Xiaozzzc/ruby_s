#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

class Learning {
public:

    void stringTest() {
        string s = "abc";
        string s1 = "hello";
        string s2 = "hello world";
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
    }

    void vecTest() {
        vector<int> left(10);  // 定义大小为 10 的vector
        vector<int> right(10, 20);  // 定义大小为 10 的vector，初始值为20

        vector<int> vec = {2, 4, 5, 1, 3, 6};

        // 将 vector 从小到大排序
        sort(vec.begin(), vec.end());

        // 将 vector 从大到小排序
        // 方法一，直接排序
        sort(vec.begin(), vec.end(), [](int a, int b) {
            return b > a;  // c++中比较函数，不可用 a - b 小到大；得用 a > b 小到大
        });

        // 方法二，从小到大排序后 reverse
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());

        int n = vec.size();
        for (int i = 0; i < n; i++) {
            cout << vec[i] << endl;
        }
    }

    void mapTest() {
        map<int, string> mp;  // map中的元素是自动按Key升序排序，跟set一样
        mp[1] = "2";
        mp[2] = "3";
        mp[3] = "4";
        mp[4] = "5";
        mp.insert(pair<int, string>(5, "6"));  // 这样插入元素

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

        // 判断是否为空
        bool b1 = mp.empty();
        if (b1) {
            cout << "map 为空" << endl;
        }
    }

    void setTest() {
        int arr[5] = {0, 1, 2, 3, 4};
        set<int> iset(arr, arr + 5);  // 由数组初始化 set

        set<int> emptySet;  // 定义空 set
        iset.insert(3);
        iset.insert(3);
        iset.insert(5);  // 添加元素
        cout << "size:" << iset.size() << endl;
        cout << "3 count = " << iset.count(3) << endl;  // set.count(x) 只能返回0或1；可用来判断元素是否存在过

        iset.erase(1);  // 删除元素

        // 遍历
        set<int>::iterator it1 = iset.begin();
        set<int>::iterator it2 = iset.end();
        for (; it1 != it2; it1++) {  // 遍历；所有元素都会根据元素的键值自动排序
            cout << *it1;
        }
        cout << endl;

        it1 = iset.find(3);
        if (it1 != iset.end())  // set 中是否存在元素
            cout << "3 found" << endl;

        it1 = iset.find(1);
        if (it1 != iset.end())
            cout << "1 not found" << endl;

        iset.clear();
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