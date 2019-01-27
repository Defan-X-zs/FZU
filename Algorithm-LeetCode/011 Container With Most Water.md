# LeetCode 011
## Container With Most Water
题目链接：https://leetcode-cn.com/problems/container-with-most-water/
解法1 语言:C 时间复杂度 O(n) 空间复杂度 O(1)
```
int min(int a, int b) {
    return (a > b) ? b : a;
}
int maxArea(int* height, int heightSize) {
    int max = 0, l = 0, r = heightSize - 1, space = 0;
    max = min(height[l], height[r]) * (r - l);
    while (l < r) {
        if (height[l] <= height[r]) {
            l++;
        }
        else {
            r--;
        }
        if (min(height[l], height[r]) * (r - l) > max) {
            max = min(height[l], height[r]) * (r - l);
        }
    }
    return max;
}
```