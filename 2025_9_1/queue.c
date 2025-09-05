// 可以用链表也可以用数组
#include "stack_queue.h"
// 初始化和销毁栈
void StackInit(Stack* pst)
{
    // 当_top追赶上容量就需要重新开辟了
    pst->_a = (STDataType*)malloc(sizeof(STDataType) * 4);
    pst->_top = 0;
    pst->_capacity = 4;
}
void StackDestroy(Stack* pst)
{
    free(pst->_a);
    pst->_a = NULL;
    pst->_top = pst->_capacity = 0;
}

// 入栈
void StackPush(Stack* pst, STDataType x)
{
    // 入栈之前需要判断栈帧内部是不是已经满了
    if(pst->_top == pst->_capacity)
    {
        pst->_capacity *= 2;
        pst->_a = (STDataType*)realloc(pst->_a, sizeof(STDataType)*pst->_capacity);
    }
    // 插入数据
    pst->_a[pst->_top++] = x;
}
// 出栈
void StackPop(Stack* pst)
{
    // 出栈需要判断是否已经出完了
    if(pst->_top == 0)
        return;
    pst->_top--;
}
// 获取数据个数
int StackSize(Stack* pst)
{
    return pst->_top;
}
// 判断栈内是否为空，如果是1就是空
int StackEmpty(Stack* pst)
{
    if(pst->_top > 0)
        return 0;
    return 1;
}
// 获取栈顶的数据
STDataType StackTop(Stack* pst)
{
    return pst->_a[pst->_top-1];
}