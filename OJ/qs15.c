// 环形链表 返回环形链表入口

// 设置环前距离是    L
// 圆环周长是        C
// 圆环起点到相遇    X

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int main() {
    // 环形链表的相关操作
    // 创建环形链表
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode* second = (struct ListNode*)malloc(sizeof(struct ListNode));
    second->val = 2;
    struct ListNode* third = (struct ListNode*)malloc(sizeof(struct ListNode));
    third->val = 3;
    head->next = second;
    second->next = third;
    third->next = head;  // 创建环

    // 检测链表是否有环
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int hasCycle = 0;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = 1;
            break;
        }
    }

    if (hasCycle) {
        // 找到环形链表的入口
        struct ListNode* entry = head;
        while (entry != slow) {
            entry = entry->next;
            slow = slow->next;
        }
        printf("环形链表的入口是: %d\n", entry->val);
    } else {
        printf("链表没有环\n");
    }

    // 释放链表内存
    struct ListNode* current = head;
    struct ListNode* next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}