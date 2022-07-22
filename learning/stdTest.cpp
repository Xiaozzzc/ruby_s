#include "iostream"

using namespace std;

// std::variant

void stdTest() {

    // std::move 将对象的状态或者所有权从一个对象转移到另一个对象
    std::string str = "Hello";
    std::vector<std::string> v;
    // simple copy
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";  // str = "Hello"
    // move
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";  // str = ""
    std::cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1] << "\"\n";
}