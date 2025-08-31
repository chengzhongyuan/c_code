#include "stack_queue.h"
int main() {
    Stack st;
    StackInit(&st);

    StackPush(&st, 10);
    StackPush(&st, 20);
    StackPush(&st, 30);

    while (!StackEmpty(&st)) {
        printf("Top: %d\n", StackTop(&st));
        StackPop(&st);
    }

    StackDestroy(&st);
    return 0;
}


// 在迷宫问题中后进先出，原路退回
// 递归改成非递归