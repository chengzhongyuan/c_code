#include <iostream>

using namespace std;
// 栈类
class Stack {
public:
    Stack(int n = 10) {
        cout << "Stack()" << endl;
        _capacity = 0;
        _size = 0;
        _a = new int[n];
    }

    // // 拷贝构造函数
    // Stack(const Stack &s) {
    //     cout << "Stack(const Stack &s)" << endl;
    // }

    // // 赋值运算符重载
    // Stack &operator=(const Stack &s) {
    //     cout << "Stack &operator=(const Stack &s)" << endl;
    //     return *this;
    // }
    ~Stack() {
        delete[] _a;
        cout << "~Stack()" << endl;
    }
private:
    int* _a;      
    int _size;  
    int _capacity; 
    
};
int main() {
    // 赋值运算符的返回值应该是*this，也可以使用引用返回
    // 传值返回存在拷贝构造，传引用不会
    // 当我们屏蔽掉拷贝被造函数和赋值运算重载时
    // 依然可以使用，代码编译不会报错

    // 1、默认构造函数，当我们不实现时编译器生成的
    // 默认构造函数:内置变量不进行处理，自定义类型变量调用默认构造函数
    // 2、拷贝构造函数，当我们不实现时编译器生成的
    // 拷贝构造函数:内置变量进行值拷贝（浅拷贝），自定义类型变量调用拷贝构造函数
    // 3、赋值运算符重载，当我们不实现时编译器生成的
    // 赋值运算符重载:内置变量进行值拷贝，自定义类型变量调用赋值运算符重载
    Stack s1; // 默认构造函数
    Stack s2 = s1; // 拷贝构造函数
    // 浅拷贝问题
    // 这个时候s1和s2的成员变量_a指向同一块内存
    // 出了作用域之后调用析构函数释放内存，同一块空间被释放了两次
    // 程序崩溃
    // 这个时候就需要自己去完成深度拷贝
    

    return 0;
}