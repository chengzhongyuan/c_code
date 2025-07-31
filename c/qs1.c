//用异或找缺失值（C语言）

#include <stdio.h>
int FindMising(int* arr,int n)
{
    int xor_full=0; //异或0~n中的所有元素
    int xor_arr=0;  //异或数组中的所有元素
    
    for(int i = 0;i<=n;i++){
        xor_full ^= i;
    }

    for(int i = 0;i<n;i++){
        xor_arr ^= arr[i];
    }
    return xor_full ^ xor_arr;
}
int main()
{
    int arr[]={0,1,3,4};//这里缺失的数字是2
    int n=sizeof(arr)/sizeof(arr[0]);
    int missing = FindMising(arr,n);
    printf("确实的数字是%d\n",missing);
    return 0;
}

/*
首先对于缺失数字二的数组来说
数组中所有的元素    0~n中所有的元素
    0：000           0：000
    1：001           1：001
    3：011           3：011
    4：100           4：100
                     2：010
异或过程中相同的直接变成0也就是说前面四个数字异或的结果是000
这个时候再去异或2就可以得到结果
*/