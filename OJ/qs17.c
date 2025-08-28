#include <stdio.h>
#include <stdlib.h>

// 删除链表之中的重复元素
 struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    // 首先处理链表之中只存在一个元素或者为空时
    if(!head || !head->next)
    {
        return head;
    }
    // 正常链表情况，我需要一个虚拟头节点
    //   prev curr
    //  dummy  2  3  3  4  NULL 
    // 这样就避免了使用头部三指针中容易存在的问题
    struct ListNode* dummy;
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;
    // 这里要考虑的是两个元素相同的情况
    while(curr)
    {
        // 跳过所有重复的节点
        if(curr->next && curr->val == curr->next->val)
        {
            while(curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
            }
            // 当我们跳出这个循环的时候，跳过整个重复段
            prev->next = curr->next;
        }
        else 
        {
            // 没有重复，正常前进
            prev = prev->next;
        }
        curr = curr->next;
    }
    return dummy->next;
}
int main()
{
    // 构建链表
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 3;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 4;
    head->next->next->next->next->next = NULL;

    // 删除重复元素
    head = deleteDuplicates(head);

    // 打印结果
    struct ListNode* curr = head;
    while (curr)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}

