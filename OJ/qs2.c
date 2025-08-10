// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。
// 元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
// 假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
// 更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
// 返回 k。

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

// 使用两个指针来进行判断，如果相同就不保留
//   prev  cur 这两个指针是紧紧挨在一起的
// 1 3 4 5 6 5 4 4 
int removeDuplicates_oj(int* nums, int numsSize)
{
    if(numsSize == 0)
        return 0;
    int prev = 0,cur = 1,dst = 0;
    while(cur < numsSize)
    {
        if(nums[prev] != nums[cur]){
            nums[dst] = nums[prev];
            prev++;
            dst++;
            cur++;
        }
        else{
            prev++;
            cur++;
        }
    }
    // 跳出循环时，cur是指向2指针之外的，最后一位数字并没有判断到
    // 所以多加一句

    // 直接加上最后一位数组空间也可以，不需要再执行判断了
    if(nums[numsSize-1] != nums[numsSize-2])
    {
        nums[dst] = nums[numsSize-1];
        dst++;
    }

    return dst;

}


#include <stdio.h>
int main()
{
    int nums[] = {1, 1, 2, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = removeDuplicates_oj(nums, numsSize);

    printf("k = %d\n", k);
    printf("修改后的数组: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}