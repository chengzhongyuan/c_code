#include"SeqList.h"

void TestSeqList1()
{
    SL s;
    SeqListInit(&s);
    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListInsert(&s, 1, 4);
}

//≤‚ ‘Õ∑Œ≤≤Â»Î…æ≥˝
int main()
{
    TestSeqList1();
    printf("TestSeqList1 passed\n");
}