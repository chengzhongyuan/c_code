#include<iostream>
using namespace std;
// 内存管理收尾
int main() {
    // 为什么c++之中要有new和delete?
    // new和delete是成对出现的
    // 对于内置类型，new和delete的作用类似于malloc和free也可以说是一样的
    int* p = new int(5);
    cout << *p << endl;
    delete p;
    // 对于自定义类型new是会自动调用构造函数，delete会自动调用析构函数
    return 0;
}