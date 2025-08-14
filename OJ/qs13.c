#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // 需要一个地址相同的地方才可以算是相交节点
    // 找到两个链表之间的差值，让大链表先走差值步数
    int Asize = 0, Bsize = 0, diffSize = 0;
    struct ListNode *tempA = headA;
    struct ListNode *tempB = headB;

    while(tempA)
    {
        Asize++;
        tempA = tempA->next;
    }
    while (tempB)
    {
        Bsize++;
        tempB = tempB->next;
    }

    if(Asize >= Bsize)
    {
        diffSize = Asize - Bsize;
        // 这个时候让A链表向前走diffSize步数补足差距
        while (diffSize)
        {
            headA = headA->next;
            diffSize--;
        }
        // 这个时候就可以同时向前走
        while(headA)
        {
            if(headA == headB)
                return headA;
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
    else if(Bsize > Asize)
    {
        diffSize = Bsize - Asize;
        // 这个时候让A链表向前走diffSize步数补足差距
        while (diffSize)
        {
            headB = headB->next;
            diffSize--;
        }
        // 这个时候就可以同时向前走
        while(headA)
        {
            if(headA == headB)
                return headA;
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
    
}

int main()
{
    // 创建公共部分：7 → 8 → 9
    struct ListNode* common = (struct ListNode*)malloc(sizeof(struct ListNode));
    common->val = 7;
    common->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    common->next->val = 8;
    common->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    common->next->next->val = 9;
    common->next->next->next = NULL;

    // 创建链表 A: 1 → 2 → 3 → common
    struct ListNode* headA = (struct ListNode*)malloc(sizeof(struct ListNode));
    headA->val = 1;
    headA->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headA->next->val = 2;
    headA->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headA->next->next->val = 3;
    headA->next->next->next = common;

    // 创建链表 B: 4 → 5 → common
    struct ListNode* headB = (struct ListNode*)malloc(sizeof(struct ListNode));
    headB->val = 4;
    headB->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headB->next->val = 5;
    headB->next->next = common;
    struct ListNode* cur = getIntersectionNode(headA, headB);

    while(cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("NULL");
    return 0;
}