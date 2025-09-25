#include <iostream>
using namespace std;

void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }
// int main()
// {
//     /* 1、const指针本身和指向的内容的区别 */
//     // const指针本身和指向的内容的区别
//     const int d = 10;
//     const int c = 10;
//     const int* p = &d;
//     p=&c;// 可以修改指针本身
//     cout << "p points to: " << *p << endl;
//     // p = nullptr; // 错误，不能修改const指针本身
//     // *p = 20; // 错误，不能修改const指针指向的内容

//     /* 2、引用的使用场景 */
//     // 引用做参数，比如交换两个变量的值
//     int a = 5;
//     int b = 10;
//     swap(a, b);
//     cout << "a: " << a << ", b: " << b << endl;

//     // 引用做返回值，比如链式调用
//     // 普通的是返回一个临时变量会产生空间，而引用返回的是一个变量的别名
//     // 临时变量具有常性，不能被修改
//     // static int temp = 0;  静态变量，生命周期为整个程序运行期间
//     // return temp;  返回临时变量的引用是错误的
//     class MyClass {
//     public:
//         MyClass& setValue(int v) {
//             value = v;
//             return *this;
//         }
//         void print() {
//             cout << "value: " << value << endl;
//         }

//     private:
//         int value;
//     };

//     MyClass obj;
//     obj.setValue(100).print();

//     return 0;
// }

int& Add(int a, int b)
{
    static int c = a + b;
    return c; 
    // 返回局部变量的引用是错误的,通过这个别名去寻找的时候，这块空间可能已经被释放了
}

int main()
{
    int& ret = Add(1,2);
    Add(3,4);
    cout << ret << endl; // 未定义行为
    return 0;
}