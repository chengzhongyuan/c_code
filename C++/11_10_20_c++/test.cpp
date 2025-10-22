#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
    /* 1、仅仅反转字母 */
    // 输入：s = "ab-cd"
    // 输出："dc-ba"
    string reverseOnlyLetters(string s) {
        // 所有非字母形式的字符留在原地
        int begin = 0;
        int end = s.size() - 1;
        while(begin < end)
        {
            // 检测首尾两个下标位置是不是字母
            if(!isalpha(s[begin])) begin++;
            else if(!isalpha(s[end])) end--;
            // 走到这里确定都是字母，所以我们可以进行交换
            else
            {
                swap(s[begin],s[end]);
                begin++;
                end--;
            }
        }
        return s;
    }
    string s1 = "ab-cd";

    /* 2、找出字符串中出现的第一个唯一字符 存在就返回索引下标 不存在就返回-1 */
    // 输入: s = "leetcode"
    // 输出: 0
    int firstUniqChar(string s) {
            // 我去建立一个数字把s[i]当成是我数组的下标
            int arr[256] = {0};
            for(int i = 0; i < s.size();i++) arr[s[i]]+=1;

            // 然后我去循环查找这个数组中第一个为1的数值
            for(int i = 0; i < s.size();i++) 
            {
                if(arr[s[i]] == 1) return i;
            }
            return -1;    
        }
    string s2 = "leetcode";

    /* 3、字符串最后一个字符的长度 输入的字符串都是使用空格进行隔开的 */
    void laststrsize()
    {
        string line;

        while(getline(cin,line))
        {
            size_t pos = line.rfind(' ');
            // hello bit
            cout<<pos<<endl;        // 这个pos位置是从零开始去数
            cout<<line.size()<<endl;// 这个是返回字符串总共有几个
            cout << "最后一个单词长度: " << line.size()-(pos+1) << endl;
        }
    }

    /* 4、验证一个字符串是否是回文字符串 */
    bool isPalindrome(string s) {
        // 首先将所有大写字母转换成小写字母，在 ASCII 表中，大小写字母之间的差值是 32。
        for(int i = 0; i<s.size();i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        }
        int begin = 0;
        int end = s.size()-1;
        while(begin < end)
        {
            // 同样也是只去考虑字母
            if(begin < end && !isalnum(s[begin])) begin++;
            else if(begin < end && !isalnum(s[end])) end--;
            else{
                if(s[begin] != s[end]) return false;
                begin++;
                end--;
            }
        }
        return true;    
    }

        /* 5、字符串相加 */
        // 输入：num1 = "11", num2 = "123"
        // 输出："134"
        string addStrings(string num1, string num2) {
        string result;
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        // 从最后开始进行尾部相加
        while (i >= 0 || j >= 0 || carry) {
            int x = i >= 0 ? num1[i--] - '0' : 0;
            int y = j >= 0 ? num2[j--] - '0' : 0;
            int sum = x + y + carry;
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
}

    

};



int main()
{
    /* 1、仅仅反转字母 */
    Solution sl;
    string s = sl.reverseOnlyLetters(sl.s1);
    cout<<s<<endl;

    /* 2、找出字符串中出现的第一个唯一字符 存在就返回索引下标 不存在就返回-1 */
    int a = sl.firstUniqChar(sl.s2);
    cout<<a<<endl;
    
    /* 3、字符串最后一个字符的长度 输入的字符串都是使用空格进行隔开的 */
    sl.laststrsize();

    return 0;


























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
    // char str[] = "中国";
    // cout<<sizeof(str)<<endl;
    // str[3] = -7;
    // cout<<str<<endl;
}