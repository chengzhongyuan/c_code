#include<iostream>
using namespace std;
class Date{
public:
    Date(int year=2024,int month=6,int day=10){
        _year=year;
        _month=month;
        _day=day;
    }
    // 拷贝构造函数  但是对象初始化的时候自动调用拷贝构造函数
    // 建议都使用Const引用
    Date(const Date &d){
        _year=d._year;
        _month=d._month;
        _day=d._day;
    }
    void display(){
        cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
    }
    // d1.operator==(&d1, d2);
    bool operator==(const Date &d){
        return _year==d._year && _month==d._month && _day==d._day;
    }
    bool operator>(const Date &d){
        if(_year!=d._year){
            return _year>d._year;
        }else if(_month!=d._month){
            return _month>d._month;
        }else{
            return _day>d._day; 
        }
    }
    
private:
    int _year;
    int _month;
    int _day;
};


int main()
{
    // 1、拷贝构造函数 
    Date d1(2020,5,4);
    Date d2(d1);// 这个就是拷贝构造，调用之前要先传参数
    Date d3=d1;// 这个也是拷贝构造
    d1.display();
    d2.display();
    d3.display();
    // 2、运算符重载 
    // 假如Date的对象想去比较大小
    d1 == d2;
    // 编译器进行这样的转换
    d1.operator==(d3);
    if(d1==d2){
        cout<<"d1==d2"<<endl;
    }
    // 五个不可以重载运算符
    // 1、::  作用域运算符
    // 2、.*  成员指针运算符
    // 3、.   成员访问运算符
    // 4、?:  三目运算符
    // 5、sizeof  sizeof运算符
    return 0;
}