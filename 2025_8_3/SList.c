#include"SList.h"
#include <assert.h>

// 打印链表
void SListPrint(SListNode* phead)
{
    SListNode* cur = phead;
    while(cur)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// 创建节点
SListNode* CreateSListNode(SListDataType x)
{
    SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
    assert(newnode != NULL); // 确保内存分配成功
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

// 尾插法
void SListPushBack(SListNode** pphead, SListDataType x)
{
    SListNode* newnode = CreateSListNode(x);

    if(*pphead == NULL){
      *pphead = newnode;
    }
    else{
        //这个时候我要找到尾部的结点指针
        SListNode* cur = *pphead;
        SListNode* tail = NULL;
        //如果这里设置的是一个cur->next
        //那么就不需要tail来保存地址了
        while(cur)
        {
            tail = cur;
            cur = cur->next;
        }
        tail->next = newnode;
    }
}

// 实现尾删
void SListPopBack(SListNode** pphead)
{
    // 如果链表为空
    if(*pphead == NULL){
        return;
    }
    // 链表中只存储了一个数据
    else if((*pphead)->next == NULL){
        free(*pphead);
        *pphead = NULL;
        return;
    }
    //链表中的数据是大于一,这个时候需要找到尾部节点和前一个节点
    //完成两件事情
    // 1. 释放最后一个节点
    // 2. 前一个节点的指向置为空
    else{
        SListNode* tail = *pphead;
        SListNode* prev = NULL;
        // 这个循环结束时tail就是最后一个值，prev记录了前一个数据
        while(tail->next != NULL)
        {
            // 指向现在的尾
            prev = tail;
            // 指向下一个
            tail = tail->next;
        }
        free(tail);
        // 如果不加入这一不的话，会出现野指针的问题
        prev->next = NULL;
    }
    
}



