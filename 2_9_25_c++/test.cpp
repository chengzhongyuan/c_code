#include <iostream>
#include <ctime>
#include <typeinfo>
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
void ModifyByValue(int val) {
    val += 1;
}

void ModifyByRef(int& val) {
    val += 1;
}
int& Add(int a, int b)
{
    static int c = a + b;// 只会执行一次这是很重要的！！
    // 此时C的生命周期为整个程序运行期间，被存储在静态区
    // 第一次调用的时候才会被执行，两个C是同一个C
    return c; 
    // 返回局部变量的引用是错误的,通过这个别名去寻找的时候，这块空间可能已经被释放了
}
// 内联函数 对编译器仅仅只是一个建议，编译器可以选择忽略
// 1、c语言使用宏函数
// 2、c++使用内联函数
// 对于频繁调用的函数，需要建立栈帧是有消耗的，使用内联函数可以减少函数调用的开销
// 但是内联函数不适合过于复杂的函数，编译器可能不会内联
// 内联函数一般定义在头文件中，在调用的地方进行展开
inline int Add_1(int a, int b) {
    return a + b;
}
int main()
{
    int& ret = Add(1,2);
    int& ret2 = Add(3,4);
    cout << ret2 << endl; 
    // 会发现打印出来的还是3，因为ret和ret2是同一个c的别名
    
    // 写一份代码展现引用的效率，用下时间戳
    // 展现引用效率
    const int N = 100000000;
    // int arr1[N] = {0};
    // int arr2[N] = {0};
    int* arr1 = new int[N]();
    int* arr2 = new int[N]();

    // 不使用引用
    size_t start = clock();
    for (size_t i = 0; i < N; ++i) {
        ModifyByValue(arr1[i]);
    }
    size_t end = clock();
    cout << "不使用引用的时间: " << double(end - start) / CLOCKS_PER_SEC << "秒" << endl;

    // 使用引用
    size_t start2 = clock();
    for (size_t i = 0; i < N; ++i) {
        ModifyByRef(arr2[i]);
    }
    size_t end2 = clock();
    cout << "使用引用的时间: " << double(end2 - start2) / CLOCKS_PER_SEC << "秒" << endl;
    delete[] arr1;
    delete[] arr2;

    // 指针和引用的区别，指针可以为空，引用必须绑定一个合法的内存地址
    // 并且在实际底层实现上，其实是一样的
    int x = 10;
    int* p = &x; // 指针
    int& r = x;  // 引用

    // auto简介 自动推导变量
    auto a = 10;        // a是int类型
    auto b = 10.5;      // b是double类型
    auto c = &x;       // c是int*类型
    // 查看类型
    cout << "a的类型: " << typeid(a).name() << endl;
    cout << "b的类型: " << typeid(b).name() << endl;
    cout << "c的类型: " << typeid(c).name() << endl;

    // NULL和nullptr
    int* p1 = NULL;    // C风格的空指针 这个会被当成0来处理
    int* p2 = nullptr; // C++11引入的空指针，更加类型安全
    return 0;
}

// 使用引用就是可以少创建拷贝一个临时对象，提高效率
