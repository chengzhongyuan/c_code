#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int HPDataType;
// 创建一个堆的结构体
typedef struct Heap
{
    // 一个动态增长的数组
    HPDataType* _a;
    int _size;
    int _capacity;
}HP;

// 堆打印
void HeapPrint(HP* php);

// 堆的初始化和销毁
void HeapInit(HP* php, HPDataType* a, int n);
void HeapDestroy(HP* php);

// 插入数据
void HeapPush(HP* php, HPDataType x);
// 删除数据
void HeapPop(HP* php);

// 获取堆顶数据
HPDataType HeapTop(HP* php);
// 堆是否为空
//bool HeapEmpty(HP* php);
// 堆的大小
int HeapSize(HP* php);
void AdjustDown(HPDataType* a, int n, int root);
// 还需要有一个交换的过程，去构建堆
void Swap(HPDataType* p1, HPDataType* p2);