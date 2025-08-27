// 带环问题
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
bool hasCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
    
}

int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = head->next; // create a cycle

    if(hasCycle(head))
    {
        printf("The list has a cycle.\n");
    }
    else
    {
        printf("The list does not have a cycle.\n");
    }

    return 0;
}