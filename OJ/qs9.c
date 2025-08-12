// 删除链表的倒数第N个节点
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
// 这份代码中会存在一个问题
// head = [1,2] n = 2 添加到测试用例 输出 [1,2] 预期结果 [2]
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //让cur先走n-1步
    struct ListNode* pre = head;
    struct ListNode* cur = head;
    // 当链表中只有一个元素时
    if(head->next == NULL)
        return NULL;
    else
    {
        int step = n-1;
        while(step)
        {
            cur=cur->next;
            step--;
        }
        //对于head = [1,2] n = 2这个测试用例，无法进入循环
        while(cur->next)
        {
            struct ListNode* prev = pre;
            pre = pre->next;
            cur = cur->next;
            if(cur->next == NULL)
            {
                prev->next = pre->next;
                free(pre);
                return head;
            }
        }
        
    }

} 
struct ListNode* removeNthFromEndOJ(struct ListNode* head, int n){
    // 创建虚拟头节点
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;

    // fast 先走 n+1 步
    for(int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // fast 和 slow 一起走，直到 fast 到达末尾
    while(fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // 删除 slow->next 节点
    struct ListNode* toDelete = slow->next;
    slow->next = toDelete->next;
    free(toDelete);

    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}


int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    int n = 2;
    head = removeNthFromEnd(head, n);

    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}