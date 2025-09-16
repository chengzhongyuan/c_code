#include "heap.h"
int main()
{
    // 构建一个简单数组，观察数组是否变成了堆
    HPDataType a[] = {2,4,6,8,9,1,7};
    // HP hp;
    // HeapInit(&hp, a, sizeof(a)/sizeof(HPDataType));
    int tail = sizeof(a)/sizeof(HPDataType) - 1;
    HeapSort(a, sizeof(a)/sizeof(HPDataType));
    for(int i = 0;i<=tail;i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}