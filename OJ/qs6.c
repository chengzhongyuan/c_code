// 需要反转链表
#include <stdio.h>
#include <stdlib.h>
typedef struct SListNode
{
    // 要存储的数据
    int data;
    // 下一个节点的地址
    struct SListNode* next;
}SListNode;

SListNode* reverseList(SListNode* head){
    if (head == NULL)
    {
       return NULL;
    }
    else if(head->next == NULL)
    {
        return head;
    }
    // 当链表中的数据大于等于二的时
    // 1地址 2地址 3地址 4地址 现在需要倒着
    // 4地址 3地址 2地址 1地址 从最后一位开始看就相当于一直进行头插
    // 进行头插得过程
    else{
        SListNode* prev = head;
        SListNode* cur = head->next;
        // 定义一个tempnode用来存储cur指向的下一个节点
        // 当cur本身为空时循环结束
        while(cur)
        {
            SListNode* tempNode = cur->next;
            cur->next = prev;
            prev=cur;
            cur = tempNode;
        }
        // 这个时候还有最后一个没有反转prev在头部 cur在尾部
        head->next = NULL;
        // 最后prev指向的就是反转后的头节点
        return prev;
    }

}

void test(SListNode* head)
{
    head->data = 100;
}

int main()
{
    SListNode* head = NULL;
    // 例如，添加节点到链表中，然后调用 reverseList(head);
    head = (SListNode*)malloc(sizeof(SListNode));
    head->data = 1;
    head->next = (SListNode*)malloc(sizeof(SListNode));
    head->next->data = 2;
    head->next->next = (SListNode*)malloc(sizeof(SListNode));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    head = reverseList(head);

    // 打印反转后的链表
    SListNode* current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d ", head->data);
    test(head);
    printf("%d ", head->data);
    return 0;
}
