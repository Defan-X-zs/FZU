# LeetCode 009
## Palindrome Number
题目链接：https://leetcode-cn.com/problems/palindrome-number/
解法1 语言:C 时间复杂度 O(log10(n)) 空间复杂度 O(1)
```
bool isPalindrome(int x) {
    if(x < 0 ||x % 10 == 0 && x != 0) return false;
    int revertedNumber = 0,number = x;
    while(number) {
        revertedNumber = revertedNumber * 10 + number % 10;
        number /= 10;
    }
    return x == revertedNumber;  
}
```
解法2 语言:Python 3 时间复杂度O( ) 空间复杂度 O(1)
```
class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        else:
            if str(x)[::-1] == str(x):
                return True
            else:
                return False
```