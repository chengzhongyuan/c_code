#include"SList.h"

//测试头尾插入删除
int main()
{
    SListNode* Node = NULL;
    //测试尾插法
    // 这里传进去的就是指针的值
    SListPushBack(&Node, 1);
    SListPushBack(&Node, 2);
    SListPushBack(&Node, 3);
    SListPrint(Node);
    SListPopBack(&Node);
    SListPrint(Node);
    SListPopBack(&Node);
    SListPrint(Node);
    SListPopBack(&Node);
    SListPrint(Node);
    printf("NULL\n");
}