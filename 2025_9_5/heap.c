#include "heap.h"
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
        AdjustDown(php->_a, php->_size, i);
    }

}


