#include "heap.h"

// 堆排序
void HeapSort(int* a, int n)
{
    // 1. 建堆
    // 假设这个有N个节点，那么树的高度logN
    // 这里的时间复杂度该如何去计算呢
    // 时间复杂度是O(N)
    for(int i=(n-1-1)/2; i >= 0; --i)
    {
        // 慢慢调整使得满足条件，左右子树都是小堆或者大堆
        AdjustDown(a, n, i);
    }
    // 想要排序把第排好的第一个最小数据放入最后，并且不放入新一轮的排序
    int end = n-1;// 记录最后一个数
    while(end > 0)
    {
        Swap(&a[0], &a[end]);

        // 再选出最小的
        AdjustDown(a, end, 0);
        --end;
    }
}
// 交换数据
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
// 先把外部给我的数组变成堆,向下调整，前提是左右子树都是小堆
void AdjustDown(HPDataType* a, int n, int root)
{
    int parent = root;
    int child = 2*parent + 1;// 这里就是左孩子
    // 然后找出左孩子和又孩子之中最小的那个
    while(child < n)
    {
        // child+1有可能越界
        if(child+1 < n && a[child + 1] < a[child])
        {
            // 此时最小的是child+1
            ++child;
        }
        // 如果a[parent]小于a[child]
        if(a[child] < a[parent])
        {
            // 完成了数据的交换
            Swap(&a[parent], &a[child]);
            parent = child;
            child = 2*parent + 1;
        }
        else{
            break;
        }
    }

}
// 初始化
void HeapInit(HP* php, HPDataType* a, int n)
{
    php->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
    memcpy(php->_a, a, sizeof(HPDataType)*n);
    php->_size = n;
    php->_capacity = n;
    // 构建堆，怎么把左右子树变成小堆
    // 从倒数第二个非叶子节点去调整
    for(int i = (n-1-1) / 2;i >= 0; --i)
    {
        // 慢慢调整使得满足条件，左右子树都是小堆或者大堆
        AdjustDown(php->_a, php->_size, i);
    }

}


