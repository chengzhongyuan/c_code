#include"SeqList.h"
#include <assert.h>

void SeqListInit(SL* s)
{
    s->a = (SLDataType*)malloc(sizeof(SLDataType)*N);
    if(s->a == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    s->size = 0; //初始化顺序表大小为0
    s->capacity = N; //初始化顺序表容量为N
}

//检查顺序表容量是否足够
//如果不够则扩容
void SeqListCheckCapacity(SeqList* ps)
{
    assert(ps);
    if(ps->size >= ps->capacity) //如果顺序表满了
    {
        ps->capacity *= 2; //扩容
        ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
        if(ps->a == NULL)
        {
            printf("内存重新分配失败\n");
            exit(1);
        }
    }
}

//尾插尾删
void SeqListPushBack(SeqList* ps, SLDataType x)
{
    assert(ps);
    SeqListCheckCapacity(ps);
    ps->a[ps->size] = x; //将x放在顺序表的末尾
    ps->size++; //顺序表大小加1
    if(ps->size >= ps->capacity) //如果顺序表满了
    {
        ps->capacity *= 2; //扩容
        /*
        realloc 可以改变由 malloc、calloc 或 realloc 分配的内存块的大小。
        如果扩展内存，realloc 会尝试在原地址扩展；如果原地址无法扩展，
        则会在新地址分配更大的空间，并把原内容复制过去，最后释放原来的空间。
        如果缩小内存，超出的部分会被释放。
        如果传入的指针为 NULL，realloc 的行为和 malloc 一样，分配新空间。
        如果新大小为 0，行为类似于 free，释放原空间并返回 NULL。
        */
        ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
        if(ps->a == NULL)
        {
            printf("内存重新分配失败\n");
            exit(1);
        }
    }
}

void SeqListPopBack(SeqList* ps)
{
    assert(ps);
    if(ps->size > 0) //如果顺序表不为空
    {
        ps->size--; //顺序表大小减1
    }
    else
    {
        printf("顺序表已空，无法删除\n");
    }
}
//头插头删
void SeqListPushFront(SeqList* ps, SLDataType x)
{
    //这一部分可以抽象成一个容量检查函数
    assert(ps);
    if(ps->size >= ps->capacity) //如果顺序表满了
    {
        ps->capacity *= 2; //扩容
        ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
        if(ps->a == NULL)
        {
            printf("内存重新分配失败\n");
            exit(1);
        }
    }
    //将元素向后移动一位
    for(int i = ps->size; i > 0; i--)
    {
        ps->a[i] = ps->a[i - 1];
    }
    ps->a[0] = x; //将x放在顺序表的开头
    ps->size++; //顺序表大小加1
}
void SeqListPopFront(SeqList* ps)
{
    assert(ps);
    if(ps->size > 0) //如果顺序表不为空
    {
        //将元素向前移动一位
        for(int i = 0; i < ps->size - 1; i++)
        {
            ps->a[i] = ps->a[i + 1];
        }
        ps->size--; //顺序表大小减1
    }
    else
    {
        printf("顺序表已空，无法删除\n");
    }
}
//指定位置插入和删除
void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
    //首先要将pos位置之后的元素全部后移一位
    SeqListCheckCapacity(ps);
    for(int i=ps->size;i>pos;i--)
    {
        ps->a[i] = ps->a[i - 1];
    }
    ps->a[pos] = x; //将x放在pos位置
    ps->size++; //顺序表大小加1

}
void SeqListErase(SeqList* ps, int pos)
{
    assert(ps);
    if(pos < 0 || pos >= ps->size) //如果pos不合法
    {
        printf("位置不合法\n");
        return;
    }
    //将pos位置之后的元素全部前移一位
    for(int i = pos; i < ps->size - 1; i++)
    {
        ps->a[i] = ps->a[i + 1];
    }
    ps->size--; //顺序表大小减1
}