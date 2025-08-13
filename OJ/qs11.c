#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

// 给定一个数值x
// 要求所有小于四的在之前，大于四在后，并且不改变原有的相对顺序

ListNode* partition(ListNode* phead,int x)
{
    // 设置了一个哨兵位的头节点
    ListNode* lessHead, *lessTail;
    ListNode* moreHead, *moreTail;
    lessHead = lessTail = (ListNode*)malloc(sizeof(ListNode));
    moreHead = moreTail = (ListNode*)malloc(sizeof(ListNode));
    lessHead->next = moreHead->next = NULL;
    
    // cur指向当前遍历的节点
    ListNode* cur = phead;
    while(cur)
    {
        if(cur->val < x)
        {
            lessTail->next = cur;
            lessTail = lessTail->next;
        }
        if(cur->val > x)
        {
            moreTail->next = cur;
            moreTail = moreTail->next;
        }
        cur = cur->next;
    }
    moreTail->next = NULL;
    lessTail->next = moreHead->next;
    ListNode* list = lessHead->next;
    free(lessHead);
    free(moreHead);
    return list;
    

}

int main()
{
    // 创建一个链表
    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    n1->val = 5, n2->val = 2,n3->val = 3,n4->val = 7,n5->val = 1;
    ListNode* curr = partition(n1,4);
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("%\n");
}