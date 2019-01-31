# LeetCode 026
## Remove Duplicates from Sorted Array
题目链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
解法1 语言:C 时间复杂度 O(n) 空间复杂度 O(1)
```
int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    if (!numsSize) return 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}
```