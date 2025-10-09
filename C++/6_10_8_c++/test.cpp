#include<iostream>
using namespace std;   
// 日期类
class Date {
public:
    Date(int year = 1970, int month = 1, int day = 1) 
        : _year(year), _month(month), _day(day) {
        cout << "Date(int, int, int)" << endl;
    }
    Date(const Date &d) 
        : _year(d._year), _month(d._month), _day(d._day) {
        cout << "Date(const Date &)" << endl;
    }
    ~Date() {
        cout << "~Date()" << endl;
    }
    // 因为this指针是隐含的一个参数,但是此时我们又必须增加const防止权限的放大
    // 所以我们把const加在函数之后,这就是const修饰成员函数
    void Print() const  // 修饰的是*this
    {
        cout << _year << "-" << _month << "-" << _day << endl;
        // _year = 2000; // 错误，不能修改成员变量
        return ;
    } 
    
    Date* operator&()
    {
        return this;
        // 不想让别人取到地址,也可以返回一个空指针
    }
private:
    int _year;
    int _month;
    int _day;
};


void f(const Date &d) {
    d.Print();
}
// 在这里实际的过程是这样的d.Print()->d.Print(&d)->Date::Print(&d)这是一个权限放大的行为
// 这里加了权限const，也就是说 const Date*，这个指针指向的内容不能被修改
/*
    const修饰的指针指向的内容不能被修改
    但是指针本身可以被修改
    举个例子
    const Date* p1;  指针指向的内容不可修改
    Date* const p2;  指针本身不可修改
    Date const *p2;  指针指向的内容不可修改

    const Date* const p3; 指针和指向的内容都不可修改
*/ 
void g(const int *p) {
    // *p = 20; // 错误，不能通过指针修改指向的内容
    p++; // 正确，可以修改指针本身
}


int n=0;

class A
{
public:
    A()
    {
        ++n;
        ++i;
    }
    A(const A& a)
    {
        ++n;
        ++i;
    }
    void Printi()
    {
        cout<<i<<endl;
    }
private:
    static int i; // 这仅仅只是一个声明
};
int A::i=0;
A f1(A a)
{
    return a;
}

int main() {    
    Date d1(2023, 10, 1); // 调用有参构造函数
    // 初始化列表是对象的成员变量定义的地方
    // 对于取地址的重载,其实就是直接返回this指针
    // 先声明先初始化,成员变量声明的顺序才是初始化的顺序
    // 内联函数不要声明和定义分离 
    int i=1;
    
    // double d = i; // 这中间存在着隐式类型转换,会产生一个临时变量,临时变量具有常性
    // double &d=i; // 所以这里加上引用之后就会报错因为出现了权限放大的情况
    const double &d=i; // 加一个const可以解决
    // 不希望隐式类型转换可以加关键字
    // explicit
    // static 静态成员变量
    // 设计一个类可以计算这个类总计产生了多少对象
    A a1;
    A a2;

    f1(a1);
    f1(a2);
    
    cout<<n<<endl;
    a1.Printi();

    return 0;  
}


/*
  1 对象调用成员函数
    博客内容首先要讲清楚const修饰成员函数
    为什么要加const?
    怎么去加const?
  2 成员函数调用成员函数 也是权限缩小的可以调用 
    成员函数调用成员函数的时候，this指针不变
*/ 