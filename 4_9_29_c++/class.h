// 实现一个完善的日期类
#include <iostream>
using namespace std;

class Date {
public:
    Date(int year = 2024, int month = 6, int day = 10) {
        _year = year;
        _month = month;
        _day = day;
    }
    // 拷贝构造函数  
    // 建议都使用Const引用
    Date(const Date& d) {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    void display() {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
    // d1.operator==(&d1, d2);
    bool operator==(const Date& d) {
        return _year == d._year && _month == d._month && _day == d._day;
    }
    bool operator>(const Date& d) {
        if (_year != d._year) {
            return _year > d._year;
        }
        else if (_month != d._month) {
            return _month > d._month;
        }
        else {
            return _day > d._day;
        }
    }

    // bool operator>=(const Date& d) {
    //     if (_year != d._year) {
    //         return _year > d._year;
    //     }
    //     else if (_month != d._month) {
    //         return _month > d._month;
    //     }
    //     else if (_day != d._day) {
    //         return _day > d._day;
    //     }
    //     else {
    //         return true;
    //     }
    // }

    // 直接调用this指针来完成>=的重载
    // 比如说我去加上时分秒，这个时候可以帮我减少工作量，需要改的地方比较少
    bool operator>=(const Date& d) {
        // 啊使用==和>来完成>=的重载
        return (*this == d) || (*this > d);
    }
    // 内聚和耦合

private:
    int _year;
    int _month;
    int _day;
};
