#include<iostream>
#include<unistd.h> // sleep
using namespace std;

// 增加一个概念，匿名对象。只有我这一行会使用这个创建对象，别人不需要使用
// 也就是说这个对象的声明周期只有那么一行
class Person{
public:
    Person() {
        cout << "构造函数调用" << endl;
    }
    ~Person() {
        cout << "析构函数调用" << endl;
    }
};


int main() {
    Person(); // 匿名对象，调用完立即析构
    // 怎么证明声明周期只存在于这一行呢

    sleep(3); // 睡眠3秒钟
    Person p; // 普通对象
    return 0;
}