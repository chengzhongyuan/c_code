#pragma once

//首先实现的是一个静态顺序表
typedef int SLDataType;
#define N 10

typedef struct SeqList
{
    SLDataType arr[N];
    int size; //当前顺序表的大小
}SeqList;

void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDataType x);
void SeqListPopFront(SeqList* ps);
