// 只出现一次的数字
// 给你一个整数数组nums，除某个元素仅出现一次外，
// 其余每个元素都恰出现三次，请你找出并返回那个只出现了一次的元素。

// 位计数法 int 类型是四个字节32位

/*
首先回顾一下左移运算符和右移运算符
? 基本定义
运算符	名称	作用描述
<<	左移运算	将数字的二进制位向左移动若干位，相当于乘以2^n
>>	右移运算	将数字的二进制位向右移动若干位，相当于除以2^n 
（向下取整）
1?? 左移 <<
int a = 3;      // 二进制: 0000 0011
int b = a << 2; // 左移2位: 0000 1100 → 十进制: 12
2?? 右移 >>
int a = 12;     // 二进制: 0000 1100
int b = a >> 2; // 右移2位: 0000 0011 → 十进制: 3

1. 位图、掩码操作（比如 1 << i 表示第 i 位）
2. 判断某一位是否为 1：(x >> i) & 1
3. 设置某一位为 1：x |= (1 << i)
4. 清除某一位：x &= ~(1 << i)
*/
#include<stdio.h>
int singleNumber(int* nums, int numsSize) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int bitsum = 0;
        for(int j = 0;j<numsSize;j++)
        {
            if((nums[j] >> i) & 1)
            {
                bitsum++;
            }
        }
        if((bitsum % 3) != 0)
        {
            result |= (1U<<i);
        }
    }
    return result;
    
}

// 使用位状态计数器（有限状态机）
int singleNumbers(int* nums, int numsSize) {
    int ones = 0, twos = 0;
    for (int i = 0; i < numsSize; ++i) {
        int num = nums[i];
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones;
}



int main()
{
    int arr[] = {2,2,3,2};
    int single = singleNumber(arr, 4) ;
    printf("%d", single);
}