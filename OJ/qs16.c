// 随机链表的复制
// 在这里面最最关键的一点就是我新拷贝节点的random就指向你的random的next

#include <stdio.h>
#include <stdlib.h>

 struct Node {
     int val;
     struct Node *next;
     struct Node *random;
 };
 

struct Node* copyRandomList(struct Node* head) {
	// 将新构造的节点依次链接在原节点的后面
    if(!head)
    {
        return NULL;
    }
    // 1. 第一轮遍历：在每个原节点后插入一个新节点
    struct Node* curr = head;
    while(curr)
    {
        struct Node* temp = curr->next;
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = curr->val;
        newnode->random = NULL;
        curr->next = newnode;
        newnode->next = temp;
        curr = temp;
    }
    // 2. 第二轮遍历：设置新节点的 random 指针。
    // 依然可以使用一个while循环来进行random赋值
    // 最关键的一句话就是新节点的random其实指向的就是源节点的random的next 
    curr = head;
    while(curr && curr->next)
    {
        if (curr->random)
            curr->next->random = curr->random->next;
        else
            curr->next->random = NULL;
        curr = curr->next->next;
    }
    // 3. 第三轮遍历：拆分链表，提取出新链表。我只想找到新拷贝的节点
    struct Node* newhead = head->next;
    // 这个头节点是我需要保存的因此我要临时构建一个copy节点
    struct Node* copy = newhead;
    while(copy && copy->next)
    {
        copy->next = copy->next->next;
        copy = copy->next;
    }
    return newhead;

}

int main()
{
    // 测试copyRandomList函数
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->val = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->val = 2;
    head->next->next = NULL;
    head->random = head->next;
    head->next->random = head;

    struct Node* newhead = copyRandomList(head);
    // 打印新链表的值和随机指针
    struct Node* curr = newhead;
    while(curr)
    {
        printf("Value: %d, Random: %d\n", curr->val, curr->random ? curr->random->val : -1);
        curr = curr->next;
    }

    // 释放内存
    curr = head;
    while(curr)
    {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    curr = newhead;
    while(curr)
    {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    return 0;
}