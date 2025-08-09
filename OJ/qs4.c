// qs4.c 88.合并两个有序数组
// 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，
// 分别表示 nums1 和 nums2 中的元素数目。
// 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
// 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
// 为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，
// 应忽略。nums2 的长度为 n 。
#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    
    
}

int main()
{
    // 在这里0并不算是元素个数，表示没有使用的空间，所以并不需要创建一个单独的数组来进行存储
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    int m = 3;
    int n = 3;
    merge(nums1, sizeof(nums1) / sizeof(nums1[0]), m, nums2, sizeof(nums2) / sizeof(nums2[0]), n);
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    return 0;
}