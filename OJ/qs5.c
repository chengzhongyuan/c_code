// 989. 数组形式的整数加法

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    
    // 首先判断k的位数
    int KSize = 0;
    // 具体的K值不可以被影响
    int KNmu = k;
    while(KNmu)
    {
        ++KSize;
        KNmu/=10;
    }
    // 数组究竟需要开多大
    int cap = (numSize > KSize ? numSize : KSize);
    int* retARR = (int*)malloc(sizeof(int) * (cap+1));

    // 数组从最后一位开始取值，要小心越界的问题
    int Ai = numSize-1;
    int reti = 0;
    int NextNum = 0;// 表示进位

    while(cap--)
    {
        int a=0;
        if(Ai >= 0)
        {
            a=num[Ai];
            Ai--;
        }

        int ret = a + k%10 + NextNum;
        // Ai--; // 这个可能会存在越界
        k /= 10;

        // 这个进位在下一轮使用
        if(ret>9)
        {
            ret-=10;
            NextNum = 1;
        }
        else
        {
            NextNum = 0;
        }
        retARR[reti++] = ret;
    }
    if(NextNum == 1)
    {
        retARR[reti++] = 1;
    }
    // 逆置数组
        int left = 0;
        int right = reti-1;
        while(left<right)
        {
            int temp = retARR[left];
            retARR[left] = retARR[right];
            retARR[right] = temp;
            ++left;
            --right;
        }
    *returnSize = reti;
    return retARR;
}

int main() {
    // 示例输入
    int num[] = {1, 2, 0, 0};
    int numSize = sizeof(num) / sizeof(num[0]);
    int k = 34;
    printf("nihao ");
    // 返回大小
    int returnSize;
    
    // 调用函数
    int* result = addToArrayForm(num, numSize, k, &returnSize);
    
    // 打印结果
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    
    // 释放内存
    free(result);
    
    return 0;
}