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

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    //用于记录唯一元素的个数
    int k=0;
    //numsSize一定是元素数量
    //对于一个数我要他左右数组中数字都不一样
    if(nums[0] != nums[1]){
        nums[k++] = nums[0];
    }
    for(int i=1;i <= numsSize-2 ; i++)
    {
        int left = i-1;
        int right = i+1;
        if(nums[i] != nums[left] && nums[i] != nums[right])//如果后一项不等于前一项
        {
            nums[k++] = nums[i];
        }
    }
    if(nums[numsSize-2] != nums[numsSize-1]){
        nums[k++] = nums[numsSize-1];
    }
    return k;
    
}
#include <stdio.h>
int main()
{
    int nums[] = {1, 1, 2, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = removeDuplicates(nums, numsSize);

    printf("k = %d\n", k);
    printf("Modified array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}