# LeetCode 283
## Move Zeroes
题目链接：https://leetcode-cn.com/problems/move-zeroes/
解法1 语言:C 时间复杂度 O(n) 空间复杂度 O(1)
```
void moveZeroes(int* nums, int numsSize) {
    int i = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != 0) nums[i++] = nums[j];
    }
    while (i < numsSize) nums[i++] = 0;
}
```