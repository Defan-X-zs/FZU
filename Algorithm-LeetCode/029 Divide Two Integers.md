# LeetCode 029
## Divide Two Integers
题目链接：https://leetcode-cn.com/problems/divide-two-integers/
解法1 语言:C 时间复杂度 O( ) 空间复杂度 O(1)
```
int divide(int dividend, int divisor) {
    long ans = 0, dend = fabs(dividend), sor = fabs(divisor);
    while(dend >= sor){
        long count = 1, base = sor;
        while(dend > (base << 1)){
            count <<= 1;
            base <<= 1;
        }
        ans += count;
        dend -= base;
    }
    ans = ((dividend < 0) ^ (divisor < 0)) ? -ans : ans;
    return (ans > INT_MAX || ans < INT_MIN) ? INT_MAX : ans;
}
//dividend = divisor*2^2 + divisor*2^1 + divisor*2^0
//ans = 2^2 + 2^1 + 2^0
```