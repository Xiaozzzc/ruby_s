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
    // const
    // inline
    // friend
    // template
    // namespace

    void stringTest() {
        // char has no initial value
        char c; // \0
        char ca;
        char cb;

        string s = "abc";
        string s1 = "hello";
        s1[1] = 'a'; // editable
        string s2 = "hello world";
        // string initial value is ""
        string s3; // ""

        string u = string(3, 'h'); // u = "hhh"
        cout << u << endl;

        // concatenation of string
        char c1 = 'a'; // 'a'
        char c2 = 'a' + 2; // 'c'
        s += s1 + s2;
        s3 += c1;
        s3 += c2;

        // s1 - s2
        int cmp = s1.compare(s2);

        // swap two strings
        s1.swap(s2);

        // find
        // s = "abchallohello world"
        int n = s.find("hel", 8); // find the first occasion of "hel" from position 8
        int n1 = s.rfind("hel"); // from back to rear, find the first occasion of "hel"

        int n2 = s.find("lef"); // 如果找不到的话返回 -1


        // Take a substring
        // From index 1 and takes a substring of length 2
        string sub = s.substr(1, 2);

        // erase
        // From index 1 and erase a substring of length 3
        s1.erase(1, 3); // 删除 从下标1开始，长度为3的子串

        // reverse
        reverse(s.begin(), s.end());

        // find
        // startWith
        if (s1.find(s2) == 0) {
        }

        // endWith
        if (s1.find(s2, s1.size() - s2.size()) != -1) {
        }

        // stoi() -> string to int
        string l = "120";
        int i = stoi(l);

        // to_string() -> int to string
        string t = to_string(i);
    }


    // update and maintain the order of vec
    // using binary search
    void update(vector<int>& items, int& item) {
        auto l = items.begin();
        auto r = items.end();
        while (l < r) {
            auto mid = l + (r - l >> 1);
            if (*mid > item) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        items.insert(l, 1, item);
    }

    /*
     * vector -> push_back(), find()
     * set -> insert(), erase(), find()
     * map -> insert(pair<int, string>()), find()
     * stack -> push(), pop(), top(), empty()
     * queue -> push(), pop(), front(), back(), empty()
     */
    void vecTest() {
        vector<int> init;
        // init[10] = 9;  会报错，因为根本没有分配空间

        init.resize(10); // init 里面 10 个 0
        init.push_back(1); // init.size() == 11
        init[20] = 90; // 并不会报错

        vector<int> left(10); // 定义大小为 10 的vector，初始值为 0
        vector<int> right(10, 20); // 定义大小为 10 的vector，初始值为 20

        iota(left.begin(), left.end(), 10); // 10, 11, 12 ...
        int sum = accumulate(left.begin(), left.end(), 0); // 将left中的元素累加，累加初始值为 0
        cout << sum << endl;

        left[100] = 100; // 不会报错，见下面 num[100] = 250
        for (vector<int>::iterator it = left.begin(); it != left.end(); it++) {
            cout << *it << endl;
        }

        int rightSize = right.size();
        right.push_back(10);
        int newRightSize = right.size();

        // 取数组最后的元素
        int bk = right.back();
        right.pop_back(); // 弹出数组最后的元素，数组元素 - 1

        vector<int> u{1, 2, 3, 4, 5};
        int l = u.back();
        vector<int> num = {2, 4, 5, 1, 3, 6};


        vector<int> vk;
        for (int n : num) {
            update(vk, n);
        }
        num.insert(num.end(), 5, 4); // 在 num 的最后面添加 5 个 4

        num.insert(num.begin(), 1, -1);

        num.insert(num.begin() + 2, 1, -1);
        int t0 = num[100]; // t0 = 0, 不会报错
        num[100] = 250; // 不会报错
        int t1 = num[100]; // t1 = 250
        int t2 = num.size(); // t2 = 11 (5 + 6)

        // sort ascending
        sort(num.begin(), num.end());

        // sort descending
        sort(num.begin(), num.end(), [](int a, int b) { return a > b; });

        // sort Two-dimensional array
        vector<vector<int>> en = {{1, 2}, {4, 1}, {3, 5}, {3, 4}, {3, 7}};
        sort(en.begin(), en.end(), [](auto& a, auto& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int n = num.size();
        for (int i = 0; i < n; i++) {
            cout << num[i] << endl;
        }

        for (int x : num) {
            cout << x << endl;
        }

        // sub vector
        vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7};
        vector<int> subVec(vec.begin() + 2, vec.begin() + 5);

        // Two-dimensional vector
        vector<vector<int>> grid(2, vector<int>(10)); // initialize
        vector<vector<int>> graph;
        graph.resize(2); // now graph has two vector that size() == 0

        vector<int> a = {1, 2, 3, 4};
        vector<int> b = {5, 6, 7};

        // 直接构建二维 vector
        graph = {a, b};
        for (auto& x : graph) {
            for (auto q : x) {
                cout << q << endl;
            }
        }
    }

    void mapTest() {
        map<int, string> mp; // map ordered by Key ascending
        unordered_map<int, string> unmp; // unordered map

        // insert
        mp[1] = "2";
        mp[2] = "3";
        mp[3] = "4";
        mp[4] = "5";
        mp.insert(pair<int, string>(5, "6")); // map is formed by pair<>

        string s1 = mp[6]; // return "" for key that doesn't exist

        map<int, int> mp1;
        mp1[1]++; // mp1[1] = 1
        int u = mp1[9]; // return 0 for key that not exist

        int qoq = mp1[3];
        cout << "size:" << mp.size() << endl;

        // map is sorted by key ascending
        map<int, string>::iterator iter1 = mp.lower_bound(1);
        // 1, "2"   not less than(greater or equal to) the given value
        map<int, string>::iterator iter2 = mp.upper_bound(1); // 2, "3"   greater than the given value
        map<int, string>::iterator iter3 = mp.find(1); // 1, "2"
        cout << iter1->second << endl;

        // map erase
        bool b = mp.erase(1);
        if (b) {
            cout << "删除了" << endl;
        }

        // map find key
        if (mp.find(1) == mp.end()) {
            cout << "not contain that element" << endl;
        }
        if (!mp.count(1)) {
            cout << "contain that element" << endl;
        }

        // map traversal
        for (map<int, string>::iterator it = mp.begin(); it != mp.end(); it++) {
            cout << it->second << endl;
        }

        // map traversal 2
        for (auto& [k, v] : mp) {
            cout << k << endl;
            cout << v << endl;
        }

        // Determine whether it is empty
        bool b1 = mp.empty();
        if (b1) {
            cout << "map 为空" << endl;
        }

        // lower_bound, upper_bound
        map<int, int> mp2;
        mp2[0] = 0;
        mp2[4] = 2;
        mp2[6] = 3;
        int lb = mp2.lower_bound(4)->first; // 4; First bigger than or equal to
        int ub = mp2.upper_bound(4)->first; // 6; First bigger than
        cout << lb << endl;
        cout << ub << endl;
    }

    void setTest() {
        int arr[5] = {0, 1, 2, 3, 4};
        set<int> iSet(arr, arr + 5); // 由数组初始化 set
        set<int> emptySet; // 定义空 set

        // 添加元素
        iSet.insert(3);
        iSet.insert(3);
        iSet.insert(5);
        // emplace 比 insert 快
        iSet.emplace(8);
        iSet.emplace(9);

        cout << "size:" << iSet.size() << endl;
        cout << "3 count = " << iSet.count(3) << endl; // set.count(x) 只能返回0或1；可用来判断元素是否存在过

        iSet.erase(1); // 删除元素

        // set traverse 1
        set<int>::iterator it1 = iSet.begin();
        set<int>::iterator it2 = iSet.end();
        for (; it1 != it2; it1++) {
            // 遍历；所有元素都会根据元素的键值自动排序
            cout << *it1;
        }
        cout << endl;

        // set traverse 2
        for (auto& u : iSet) {
            // ...
            cout << u << endl;
        }

        // set find
        int n1 = iSet.count(3); // set.count(x) 只能返回0或1；可用来判断元素是否存在过
        if (n1 == 0) {
            cout << "3 not found" << endl;
        }
        it1 = iSet.find(3);
        if (it1 != iSet.end()) // set 中是否存在元素
            cout << "3 found" << endl;

        it1 = iSet.find(1);
        if (it1 != iSet.end())
            cout << "1 not found" << endl;

        auto it = lower_bound(iSet.begin(), iSet.end(), 4); // ???
        iSet.clear();
    }

    void stackTest() {
        stack<int> stack;
        stack.push(1); // .push()
        if (!stack.empty()) {
            int top = stack.top(); // .top()
            cout << top << endl;
            stack.pop();
        }
    }

    /*
     * .push()
     * .top()  return the first element
     * .pop()  return void
     * .empty()
     * .back()
     * .front()
     */
    void queueTest() {
        queue<string> queue; // 定义queue
        queue.push("3"); // 添加元素
        if (!queue.empty()) {
            // 判空
            string front = queue.front(); // 取最前元素
            string back = queue.back();
            queue.pop();
        }
    }

    void priorityQueueTest() {
        // Descending by default
        // 默认大顶堆；等同于 priority_queue<int, vector<int>, less<int> > a;
        priority_queue<int> a; // descending
        priority_queue<int, vector<int>, greater<int>> c; // 这样就是小顶堆

        priority_queue<string> b;

        for (int i = 0; i < 5; i++) {
            a.push(i);
            c.push(i);
        }

        while (!a.empty()) {
            // 判空
            cout << a.top() << ' '; // 取顶
            a.pop(); // 后弹出
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

    void dataStructureTest() {
        tuple<int, char, double> myTuple(10, 'a', 3.14);
        pair<int, string> p(0, "sss");
        pair<int, string> p1 = make_pair(9, "9");
        std::cout << "myTuple has ";
        std::cout << std::tuple_size<decltype(myTuple)>::value;
        std::cout << " elements." << '\n';
    }

    void memcpyTest() {
        vector<int> dist = {-1, 0, 1};
        vector<int> speed = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};

        vector<int> res;
        res.resize(10); // reset the length of vector to 10

        // res.data() + 1，这里的 1 是 一个 vector 元素，而不是一个字节
        // dist.data() 表示 vector<int> dist 的起始位置
        // dist.size() * sizeof(int) 表示字节长度
        memcpy(res.data() + 1, dist.data(), dist.size() * sizeof(int));
    }
};
