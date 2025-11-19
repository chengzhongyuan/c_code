#include <iostream>
using namespace std;

/* 1、非类型模板函数，首先回顾一下模板类型函数 */
template <class T>
T add(T a, T b)
{
    return a + b;
}
// 为什么我们需要非类型的模板函数
// 模板参数分类类型形参与非类型形参。
// 类型形参即：出现在模板参数列表中，跟在class或者typename之类的参数类型名称。
// 非类型形参，就是用一个“常量”作为类(函数)模板的一个"参数"，在类(函数)模板中可"将该参数当成常量来使用"。

namespace bite
{
    // 定义一个模板类型的静态数组
    template <class T, size_t N = 10>
    class array
    {
    public:
        // 重载来实现下标访问
        T &operator[](size_t index) { return _array[index]; }
        const T &operator[](size_t index) const { return _array[index]; }

        size_t size() const { return _size; }
        bool empty() const { return 0 == _size; }

    private:
        T _array[N];
        size_t _size;
    };
}
/*
注意：
1. 浮点数、类对象以及字符串是不允许作为非类型模板参数的。
2. 非类型的模板参数必须在编译期就能确认结果。
*/

/* 2、类模板的特化 a.函数模板特化 b.类模板特化 */
// 函数模板 -- 参数匹配
template <class T>
bool Less(T left, T right)
{
    return left < right;
}
// a.函数模板特化,或者说也是可以直接给出，所以对于参数类型复杂的就不建议特化了建议直接给出
template<>
 bool Less<int*>(int* left, int* right)
 {
    return *left < *right;
 }
 // 这就是直接给出的
bool Less(int* left, int* right)
{
   return *left < *right;
}
// b.类模板特化
template<class T1,class T2>
class Data
{
public:
    Data() {cout<<"Data<T1,T2>" <<endl;}
private:
    T1 _t1;
    T2 _t2;
};
// 全部特化
template<> 
class Data<int, char>
 {
 public:
    Data() {cout<<"Data<int, char>" <<endl;}
 private:
    int _d1;
    char _d2;
 };
 // 偏特化
template<class T1> 
class Data<T1, char>
 {
 public:
    Data() {cout<<"Data<T1, char>" <<endl;}
 private:
    T1 _d1;
    char _d2;
 };
// 对参数进行进一步的设置
template <typename T1, typename T2>
 class Data <T1&, T2&>
 {
    public:
    Data(const T1& d1, const T2& d2): _d1(d1), _d2(d2)
    {
    cout<<"Data<T1&, T2&>" <<endl;
    }
    private:
    const T1 & _d1;
    const T2 & _d2; 
 };
void TestVector()
 {
    Data<int, int> d1;
    Data<int, char> d2;
    Data<char, char> d3;
    Data<int&, int&> d4(1,2);
 } 

 /* 3、模板的分离编译 */
int main()
{
    // 1、使用示例
    add<int>(1, 2);

    // 2、使用示例
    cout << Less(1, 2) << endl; // 可以比较，结果正确
    int d1 = 1;
    int d2 = 2;
    int *p1 = &d1;
    int *p2 = &d2;
    cout << Less(p1, p2) << endl; 
    // 可以比较，但是输出结果错误所以就需要在原先模板类的基础上针对特殊类型进行特殊化的实现方式
    /*
    (base) PS D:\Code\bite\C++\14_11_19_c++> .\test.exe
    1
    0
    */
    TestVector();
    /* 3、模板的分离编译 */
    return 0;
}