#include<iostream>
#include<assert.h>
#include<cstring>
using namespace std;
/* 1、string类的模拟实现 */ 

class String{
public:
    // 实现String的构造函数
    String(const char* str = "")
    {
        if(str == nullptr)
        {
            assert(false);
            return;
        }
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }
    // 实现拷贝构造函数解决浅拷贝造成的访问违规问题
    String(const String& s)
        :_str(new char[strlen(s._str)+1])
    {
        strcpy(_str,s._str);
    }
    ~String()
    {
        if(_str)
        {
            delete[] _str;
            _str = nullptr;
        }
    }
    void Print()
    {
        printf("%s\n",_str);
    }
    
    // 这里的s是一个值传递的副本
    String& operator=(String s){
        swap(_str,s._str);
        return *this;
    }

    // 也可以尝试使用一种引用的形式
    // String& operator=(const String& s)
    // {
    //     // 判断是不是传递了自身
    //     if(this != &s)
    //     {
    //          String strTmp(s);
    //          swap(_str,strTmp._str);
    //     }
    //     return *this;
    // }
private:
    char* _str;

};

int main()
{
    String s1("nullptr");
    // s2需要使用String类拷贝构造函数来进行实现，但是并没有显示定义，所以使用系统合成的默认拷贝构造函数 
    // 此时编译器会合成默认的，当用s1构造s2时，编译器会调用默认的拷贝构造。最终导致的问题是，s1、s2共用同一块内存空间，在释放时同一块
    // 空间被释放多次而引起程序崩溃
    /* 
    浅拷贝：也称位拷贝，编译器只是将对象中的值拷贝过来。如果对象中管理资源，最后就会导致多个对象共
    享同一份资源，当一个对象销毁时就会将该资源释放掉，而此时另一些对象不知道该资源已经被释放，以为
    还有效，所以当继续对资源进项操作时，就会发生发生了访问违规。
    */
    String s2(s1);
    String s3("xxx");
    s1.Print();
    s2.Print();
    s1 = s3;
    s1.Print();
    s3.Print();
    return 0; 
}