# LeetCode 007
## Reverse Integer
题目链接：https://leetcode-cn.com/problems/reverse-integer/
解法1 时间复杂度 O(log10(n)) 空间复杂度 O(1)
```
int reverse(int x) {
    long long s = 0;
    while(x != 0) {
        s = s * 10 + x % 10;
        x /= 10;
    }
    if(s < -2147483648|| s > 2147483647) return 0; 
    else return s;
}
```
