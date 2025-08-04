#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//首先实现的是一个链表
typedef int SListDataType;
#define N 10

typedef struct SListNode
{
    SListDataType data;
    struct SListNode* next;
}SListNode;

//尾插尾删
void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);
//头插头删
void SListPushFront(SListNode** pphead, SListDataType x);
void SListPopFront(SListNode** pphead);

//指定位置插入和删除
void SListInsert(SListNode** pphead, int pos, SListDataType x);
void SListErase(SListNode** pphead, int pos);

//打印链表
void SListPrint(SListNode* phead);

//创建节点
SListNode* CreateSListNode(SListDataType x);