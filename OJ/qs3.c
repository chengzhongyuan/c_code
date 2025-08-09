#include <stdio.h>
void quicksort(int* nums, int left, int right) {
    if (left >= right) return;

    int pivot = nums[left];  
    //pivot是选定的一个基准值每次都会重新选一个
    //在这里每次选定的都是第一个
    int i = left, j = right;
	
    //如果是复合左右两边的直接减减，知道遇到两边都不满足要求
    //这个时候就可以进入if循环
    while (i < j) {
        while (i < j && nums[j] >= pivot) 
            j--;
        while (i < j && nums[i] <= pivot) 
            i++;
     //对他们进行对换
        if (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    nums[left] = nums[i];
    nums[i] = pivot;//这个时候将piovt放到中间位置
	
    //对左右接着进行快排又是一个新的小部分知道只剩下一个数字
    quicksort(nums, left, i - 1);
    quicksort(nums, i + 1, right);
}

int main() {
    int nums[] = {3, 6, 8, 10, 1, 2, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    quicksort(nums, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}