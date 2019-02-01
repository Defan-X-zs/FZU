# LeetCode 027
## Remove Element
题目链接：https://leetcode-cn.com/problems/remove-element/
解法1 语言:C 时间复杂度 O(n) 空间复杂度 O(1)
```
int removeElement(int* nums, int numsSize, int val) {
    int i = 0, j = 0;
    for (; j < numsSize; j++) {
        if (nums[j] == val) {}
        else nums[i++] = nums[j];
    }
    return i;
}
```