// 回文链表
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

ListNode* revList(ListNode* phead)
{
    // 之前讲到过逆置链表两种方法
    // 这里使用原地逆置
    if(phead == NULL)
    {
        return NULL;
    }
    else if(phead->next == NULL)
    {
        return phead;
    }
    else{
        ListNode* n1, *n2, *n3;
        n1 = NULL;
        n2 = phead;
        n3 = phead->next;
        // 当n2为空时才结束逆置
        while(n2)
        {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if(n3 != NULL)
            {
                n3 = n3->next;
            }
        }
        return n1;
    }
}

bool isPalindrome(struct ListNode* head) {
    // 先通过快慢指针找到中间值
    ListNode* slow, *fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* middleNode = slow;
    free(slow);
    free(fast);
    // 然后逆置链表
    slow = revList(slow);

    
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
    n1->val = 1, n2->val = 2,n3->val = 3,n4->val = 2,n5->val = 1;
    int a = isPalindrome(n1);
    printf("%d", a);
    
}