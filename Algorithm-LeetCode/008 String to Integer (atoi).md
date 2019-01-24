# LeetCode 008
## String to Integer (atoi)
题目链接：https://leetcode-cn.com/problems/string-to-integer-atoi/
解法1 语言:C 时间复杂度 O(n) 空间复杂度 O(1)
```
int myAtoi(char* str) {
    int i = 0, f = 1;
        long res = 0;
        while (str[i] == ' ') { 
            i++;
        }
        if (str[i] == '-') {
            f = -1;
            i++;
        }
        else if (str[i] == '+') {
            i++;
        }
        if (str[i] <= '9' && str[i] >= '0') {
            while (str[i] <= '9' && str[i] >= '0') {
                res = res * 10 + str[i] - '0';
                i++;
                if (res * f < -2147483648) return -2147483648;
                if (res * f > 2147483647) return 2147483647;
            }
            
        } 
        return res * f;
}
```