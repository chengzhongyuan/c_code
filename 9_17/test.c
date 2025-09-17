#include<stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TNode;

// 递归前序遍历
void PrevOrder(TNode* root)
{
    if(root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%d ",root->val);
    PrevOrder(root->left);
    PrevOrder(root->right);

}

// 递归中序遍历
void InOrder(TNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    InOrder(root->left);
    printf("%d ", root->val);
    InOrder(root->right);
}

// 递归后序遍历
void PostOrder(TNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->val);
}


// 二叉树大小
int TreeSize(TNode* root)
{
    if (root == NULL)
        return 0;
    return 1 + TreeSize(root->left) + TreeSize(root->right);
    // 其实所有的数据增加都是靠这个1走到根部之后都是0
    
}

// 如果我只想要叶子节点的个数呢
int LeafCount(TNode* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return LeafCount(root->left) + LeafCount(root->right);
}

TNode* newNode(int v) {
    TNode* p = (TNode*)malloc(sizeof(TNode));
    if (!p) return NULL;
    p->val = v;
    p->left = p->right = NULL;
    return p;
}

TNode* buildExampleTree() {
    TNode* A = newNode(1); // A
    TNode* B = newNode(2); // B
    TNode* C = newNode(3); // C
    TNode* D = newNode(4); // D
    TNode* E = newNode(5); // E
    TNode* F = newNode(6); // F

    A->left  = B;
    A->right = C;

    B->left  = D;
    B->right = E;

    C->left  = NULL;
    C->right = F;

    return A;
}
/*
创建的二叉树的直观结构
        A
       / \
      B   C
     / \   \
    D   E   F
*/

void freeTree(TNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


 int main()
 {
    TNode* A = buildExampleTree();
    PrevOrder(A);
    printf("\n");
    InOrder(A);
    printf("\n");
    PostOrder(A);
    printf("\n");
    int size = TreeSize(A);
    printf("Tree size = %d\n", size); // 预期输出：Tree size = 6
    freeTree(A);
    return 0;
 }