
// 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，
// 使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
// 然后返回 nums 中唯一元素的个数。
// 考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
// 更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
// 返回 k 。

// 要实现一个函数去除数组中的重复元素，并返回新数组的长度。
// 我只需要和后一个数字去比较，如果后一个不一样的话一定没有重复的
// int removeDuplicates(int* nums, int numsSize) {
//     if (numsSize == 0) return;

//     int k = 1; // k 用于记录唯一元素的数量
//     for (int i = 1; i < numsSize; i++) {
//         if (nums[i] != nums[k - 1]) { // 如果当前元素与前一个唯一元素不同
//             nums[k++] = nums[i]; // 将当前元素添加到前 k 个元素中
//         }
//     }
//     // k 即为新数组的长度
//     return k;
// }
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

// 可以在同一个数组上标定上两个下标，直接在原数组上进行覆盖
//    src
// 1 3 4 5 6 5 4 
//    dst

int removeElements(int* nums, int numsSize, int val)
{
    int src = 0;
    int dst = 0;
    while(src < numsSize)
    {
        if(nums[src] != val)
        {
            nums[dst] = nums[src];
            src++;
            dst++;
        }
        else{
            src++;
        }
    }
    return dst;
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