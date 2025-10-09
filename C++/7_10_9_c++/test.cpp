#include<iostream>
using namespace std;

// 对于这样一个类直接就会进入循环在这里无限的加上去，需要加上一个截止的条件
class Sum
{
private:
    
public:
    static int _i;
    static int _sum;
    Sum()
    {
        _sum += ++_i;
    }
};
int Sum::_i = 0;
int Sum::_sum = 0;

class Sloution
{
public:
    int SumSloution(int n)
    {
        // 这个时候我希望创建n个对象，首先解释一下为什么要创建n个
        /*
            举个例子：
            假设 n = 3，那么这行代码会创建 3 个对象：
            第一个对象：count = 1，sum = 1
            第二个对象：count = 2，sum = 3
            第三个对象：count = 3，sum = 6
            并且因为sum是静态变量也就是说任意读取一个数值就是最终的结果
        */
       Sum* ARR = new Sum[n];
       delete[] ARR; // 完成对内存的释放
       return Sum::_sum;
    }
};
class Date
{
    friend ostream& operator<<(ostream& out,const Date& d);
    friend istream& operator>>(istream& in, Date& d);
// public:
//     void operator<<(ostream& out)
//     {
//         out<<_year<<_month;
//     }
private:
    int _year = 10; // 这里的操作不是初始化，而是给了一个缺省值，这很重要
    int _month = 10;
};
istream& operator>>(istream& in, Date& d)
{
    in>>d._year>>d._month;
    return in;
}
ostream& operator<<(ostream& out,const Date& d)
    {
        out<<d._year<<"_"<<d._month<<endl;
        return out;
    }
int main()
{
    // 静态成员函数没有this指针
    // static成员变量不存在与对象之中，存在静态区，属于这个类的所有对象，也是属于这个类
    // 静态可以调用非静态的吗  不可以因为没有this指针啊
    // 非静态的可以调用静态的
    
    /*
    求1+2+3+..+n，
    要求不能使用乘除法、for、while、if、else、switch、case等关键字
    及条件判断语句(A?B:C)
    */ 
   Sloution s1;
   int a = s1.SumSloution(6);
    cout<<a<<endl;

    // 友元和为什么需要友元
    // 举例一个必须使用友元的情况
    Date d1;
    Date d2;
    // d1.operator<<(cout);
    // d1<<cout;
    // 这里为什么是这样的呢，隐藏的那个是左操作数抢了第一个的位置，输入的是右操作数
    // 所以我在外面使用友元函数，为什么要写到类外面呢，这样就不存在所谓的this指针了，但是同时我还是需要
    // 这个里面的私有成员变量，这个时候蜗我就必须要去使用友元函数
    cout<<d1<<d2;
    // 类是一个友元
    return 0;
}