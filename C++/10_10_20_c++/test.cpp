#include<iostream>
#include<string>
using namespace std;

/* 
    关于string学习
    1、熟悉使用
    2、了解底层使用原理
*/
void test_string()
{
    std::string s0("Initial string");
    /* (1) default string(); 默认拷贝构造函数,这就是直接生成一个空串*/
    std::string s1;
    /* (2) copy	string (const string& str); 拷贝构造*/
    std::string s2(s0);
    /* (3) substring string (const string& str, size_t pos, size_t len = npos); 从哪里开始拷贝，然后到什么时候结束*/
    std::string s3(s0, 2, 4); //拷贝四个
    std::string s8(s0, 2, std::string::npos); //之后的全部拷贝
    /* (4) from c-string string (const char* s); */
    std::string s4("字符串拷贝");
    /* (5) from buffer	string (const char* s, size_t n); 要拷贝前几个*/
    std::string s5("12345", 3);
    /* (6) fill constructor	string (size_t n, char c); 填充构造也可以使用ASCII码值*/
    std::string s6(10, 'x'); 
    
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s8<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;
    cout<<s6<<endl;
}
void test_iterate_1()
{
    string s1("hello");
    s1 += " ";
    s1 += "world";
    // 每个字符之上加1
    // 输出变成 i f m m p ! x p s m e
    for(int i=0; i<s1.size() ;i++)
    {
        s1[i] += 1;
    }
    // 读取
    for(int i=0; i<s1.size() ;i++)
    {
        cout<<s1[i]<<" ";
    }
    cout<<endl;
}

void test_iterate_2()
{
    string s1("hello");
    s1 += " ";
    s1 += "world";
    
    string::iterator it = s1.begin();
    while(it != s1.end())
    {
        *it -= 1;
        ++it;
    }
    it = s1.begin();
    // 迭代器并不一定是一个指针，暂时可以想象成像指针一样的东西
    while(it != s1.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    // 范围for,他是可以自动进行加加的，他的原理也是被替换成迭代器
    for(auto ch:s1)
    {
        cout<<ch<<" ";
    }
    cout<<endl;
}

void test_reverse_iterator()
{
    string s1("hello");
    s1 += " ";
    s1 += "world";

    string::reverse_iterator rit = s1.rbegin();
    while(rit != s1.rend())
    {
        cout<<*rit<<" ";
        ++rit;
    }
    cout<<endl;

}
int string2int(const string& str)
{
    int val = 0;
    string::const_iterator it = str.begin();
    while(it != str.end())
    {
        val *= 10;
        val += (*it-'0');// 得到的就是我们需要的数字
        ++it;
    }
    return val;
}

void my_resize()
{
    std::string str ("I like to code in C");
    std::cout << str << '\n';
    
    str.resize (str.size()+2,'+'); // 再增加两个字符在后面
    std::cout << str << '\n';

    str.resize (14);// 只输出14个
    std::cout << str << '\n';
 
}
void my_reverse()
{
    // 请求将字符串的容量（capacity）调整为最多可容纳 n 个字符的大小，以适应预期的长度变化。
    std::string str;
    str.reserve(100);  // 预留至少 100 个字符的空间

}
int main()
{
    /* 1、四个默认成员函数 */
    test_string();

    /* 2、字符串遍历[]+下标 */
    test_iterate_1();
    
    /* 3、迭代器遍历 */
    test_iterate_2();

    /* 4、其他迭代器 */
    test_reverse_iterator();

    /* 5、字符串转整形 */
    string s1("333");
    cout<<string2int(s1)<<endl;

    /* 6、resize */
    my_resize();

    /* 7、reverse */
    my_reverse();

    return 0;
}