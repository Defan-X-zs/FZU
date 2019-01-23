# LeetCode 004
## Median of Two Sorted Arrays
题目链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
解法1 语言:C 时间复杂度 O(n*n) 空间复杂度 O(n+m)
```
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums3Size = nums1Size + nums2Size, nums3[nums3Size],i,j,tmp;
    for (i = 0;i < nums2Size ; i++) {
        nums3[i] = nums2[i];
    }
    for (i = nums2Size, j = 0; i < nums3Size; i++, j++) {
        nums3[i] = nums1[j];
    }
    for (i = 0; i < nums3Size; i++)// 冒泡排序
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
解法2 语言:C 时间复杂度 O(n) 空间复杂度 O(n+m)
```
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size, *nums = malloc(sizeof(int) * size), i, j, k;
    for (i = 0, j = 0, k = 0; i < size; i++) {
        if (j != nums1Size && k != nums2Size) { // 二路归并
            if (nums1[j] <= nums2[k]) {
                nums[i] = nums1[j];
                j++;
            }
            else {
                nums[i] = nums2[k];
                k++;
            }
        }
        else if (j != nums1Size && k == nums2Size) {
            nums[i] = nums1[j];
            j++;
        }
        else if (j == nums1Size && k != nums2Size) {
            nums[i] = nums2[k];
            k++;
        }
    }
    if (size % 2) return nums[(size / 2)];
    else return (nums[(size / 2)] + nums[(size / 2) - 1]) / 2.0;
}
```