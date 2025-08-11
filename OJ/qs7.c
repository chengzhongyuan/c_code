// 移除链表元素
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* lastnode = head;
    struct ListNode* newhead = head;
    // 这个用于指示是否是第一个头
    int I = 0;
    //直接让头节点依次去链接
    while(cur)
    {
        if(cur->val != val)
        {
           if(I == 0)
           {
                newhead = cur;
                lastnode = cur;
                cur = cur->next;
           }
           else
           {
                lastnode->next = cur;
                lastnode = cur;
                cur = cur->next;
           }
           I = 1;
        }
        else
        {
            cur = cur->next;
        }
    }
    return newhead;
}


// 课程代码
struct ListNode* removeElement(struct ListNode* head, int val)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;

    while(cur)
    {
        // 当遇到值相等时的情况
        if(cur->val == val)
        {
            if(cur == head)
            {
                head=cur->next;
                free(cur);
                cur = head;
            }
            // 遇到相同值并且不是头节点
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        // 没有遇到时正常的迭代
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    
}
int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = NULL;

    head = removeElements(head, 2);

    // 打印结果
    struct ListNode* cur = head;
    while (cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }

    return 0;
}