# LeetCode 004
## Median of Two Sorted Arrays
题目链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
解法1 语言:C 时间复杂度 O( ) 空间复杂度 O( )
```
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums3Size = nums1Size + nums2Size, nums3[nums3Size],i,j,tmp;
    for (i = 0;i < nums2Size ; i++) {
        nums3[i] = nums2[i];
    }
    for (i = nums2Size, j = 0; i < nums3Size; i++, j++) {
        nums3[i] = nums1[j];
    }
    for (i = 0; i < nums3Size; i++)
        for (j = i + 1; j < nums3Size; j++)
            if (nums3[i] > nums3[j]) {
                tmp = nums3[i];
                nums3[i] = nums3[j];
                nums3[j] = tmp;
            }
    if (nums3Size % 2) return nums3[(nums3Size / 2)];
    else return (nums3[(nums3Size / 2)] + nums3[(nums3Size / 2) - 1]) / 2.0;
}
```