// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。
// 元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
// 假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
// 更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
// 返回 k。
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k++] = nums[i];
        }
        //这里是相当于重新理出了一个数组
    }
    return k;
}

// 示例测试代码
int main() {
    int nums[] = {3, 2, 2, 3};
    int val = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = removeElement(nums, numsSize, val);

    printf("k = %d\n", k);
    printf("Modified array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}