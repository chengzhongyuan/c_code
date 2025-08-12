// 链表的中间节点
#include <stdio.h>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;

}

int main()
{
    // 创建链表 1->2->3->4->5
    struct ListNode n5 = {5, NULL};
    struct ListNode n4 = {4, &n5};
    struct ListNode n3 = {3, &n4};
    struct ListNode n2 = {2, &n3};
    struct ListNode n1 = {1, &n2};

    struct ListNode* mid = middleNode(&n1);
    printf("Middle node value: %d\n", mid->val);

    return 0;
}