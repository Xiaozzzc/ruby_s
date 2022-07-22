#include "iostream"

struct Foo {
    ~Foo() { std::cout << "destruction" << std::endl; }
};

Foo FooFactory() {
    return Foo();
}

void operatorTest() {

    // && 右值引用
    std::cout << "before copy constructor..." << std::endl;
    Foo foo1 = FooFactory();  // 这一步，会创建一个 Foo 对象（右边），再复制创建左边的对象，总共创建、销毁两个对象，打印两个 "destruction" (clang 编译器)
    std::cout << "after copy constructor..." << std::endl << std::endl;
    // && 表示引用右值，避免生成新对象
    Foo &&foo2 = FooFactory();
    std::cout << "life time ends!" << std::endl << std::endl;
}