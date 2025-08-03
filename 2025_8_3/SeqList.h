#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//首先实现的是一个静态顺序表
typedef int SLDataType;
#define N 10

typedef struct SeqList
{
    SLDataType* a;
    int size; //当前顺序表的大小
    int capacity; //当前顺序表的容量
}SL, SeqList;

//初始化顺序表
//注意这里的参数是一个结构体类型的变量
void SeqListInit(SL* s);
//尾插尾删
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps);
//头插头删
void SeqListPushFront(SeqList* ps, SLDataType x);
void SeqListPopFront(SeqList* ps);
//指定位置插入和删除
void SeqListInsert(SeqList* ps, int pos, SLDataType x);
void SeqListErase(SeqList* ps, int pos);

void SeqListCheckCapacity(SeqList* ps);