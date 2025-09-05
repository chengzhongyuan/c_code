#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int STDataType;
typedef struct Stack {
    STDataType *_a;
    int _top;  // 栈顶元素下标
    int _capacity;
} Stack;

// 初始化和销毁栈
void StackInit(Stack* pst);
void StackDestroy(Stack* pst);

// 入栈
void StackPush(Stack* pst, STDataType x);
// 出栈
void StackPop(Stack* pst);
// 获取数据个数
int StackSize(Stack* pst);
// 判断栈内是否为空，如果是1就是空
int StackEmpty(Stack* pst);
// 获取栈顶的数据
STDataType StackTop(Stack* pst);

// 静态栈
// typedef struct {
//     int _a[100];
//     int _size;
// } StaticStack;

