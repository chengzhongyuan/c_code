#include<iostream>
using namespace std;
int main()
{
    // 编码表 值和表示符号映射关系
    // ASCII码表
    // for(unsigned char ch = 0; ch < 255; ++ch)
    // {
    //     cout<<ch<<" ";
    // }
    // cout << endl;

    // 中文表示
    // unicode这是一个统一的映射
    // utf8 utf16 utf32
    char str[] = "中国";
    cout<<sizeof(str)<<endl;
    str[3] = -7;

    cout<<str<<endl;
    
    return 0;
}