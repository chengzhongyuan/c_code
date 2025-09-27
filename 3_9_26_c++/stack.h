//1、 声明和定义的区别
// 声明：告诉编译器这个东西存在
// 定义：实现这个函数
#include <iostream>
class Stack
{
    //1、六个默认成员函数列出
    
    // 拷贝构造函数
    // 赋值运算符重载函数
    
    // 移动构造函数
    // 移动赋值运算符重载函数
    public:
    // 可以在类里面定义也可以在里面声明在外面定义
    Stack(int size); // 构造函数
    ~Stack(); // 析构函数
    void push(int value);
    int pop();
    bool isEmpty();
    bool isFull();
    //2、成员变量
private:
    int _top;
    int _maxSize;
    int* _stackArray;
};
class Time
{
    public:
    Time()
    {
        _hour = 0;
        _minute = 0;
        _second = 0;
        std::cout<< "Time()" << std::endl;
    }

private:
    int _hour;
    int _minute;
    int _second;
};
class A1
{
    public:
    /*
    实际上编译器会做这样的一个处理
    void PrintDate(Date* this)
    {
        std::cout << "Date: " << this->_year << "-" << this->_month << "-" << this->_day << std::endl;
    }
        this指针存在哪里？存在栈上，因为是一个形参
        什么时候创建？什么时候销毁？
        什么时候传递？调用成员函数的时候传递
        什么时候使用？在成员函数中使用
    */

   // 默认构造函数(函数名和类名相同) 创建实例的时候传入参数 构造函数重载
   // 不显示定义，编译器会生成无参的默认构造函数
//    A1(int year, int month, int day)
//    {
//         _year = year;
//         _month = month;
//         _day = day;
//    }
//    A1()
//    {
//         _year = 0;
//         _month = 0;
//         _day = 0;
//    }
   // 上面两个可以合二为一，全缺省概念。想传几个参数就传几个
   // 上下两个不可以同时存在，否则调用会有歧义

   // 析构函数 对象声明结束会进行调用,资源清理 这个是倒着析构的·
    ~A1()
    {
        std::cout << "~A1()" << std::endl;
    }
    A1(int year=2024, int month=6, int day=26)
    {
        _year = year;
        _month = month;
        _day = day;
    }


    void PrintDate()
    {
        std::cout << "Date: " << _year << "-" << _month << "-" << _day << std::endl;
    }
    void PrintNoDate()
    {
        std::cout << "PrintNoDate" << std::endl;
    }
    private:
    int _year;   
    int _month;
    int _day;
    Time t1; 
    // 这个对于内置类型的变量没有处理
    // 这个对于自定义类型的变量会调用默认构造函数 
};

// 不能在构造函数上面返回指定的类型
// 构造函数没有返回值
// 为什么这里不需要传参数呢，编译器会自动传递一个this指针
// this指针指向调用这个函数的对象

Stack::Stack(int size)
{
    _maxSize = size;
    _top = 0; 
    _stackArray = new int[_maxSize];
}

Stack::~Stack()
{
    if(_stackArray != nullptr)
    {
        delete[] _stackArray;
        _stackArray = nullptr;
    }
}