# LeetCode 003
## Longest Substring Without Repeating Characters
题目链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
解法1 语言:C++ 时间复杂度 O(n) 空间复杂度 O(min(m,n))
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length(), ans = 0;
        map<char, int> strmap;
        for (int l = 0, r = 0; r < len; r++) {
            if (strmap.count(s[r])) {
                l = (strmap[s[r]] > l ? strmap[s[r]] : l);
            }
            ans = (ans > r - l + 1 ? ans : r - l + 1);
            strmap[s[r]] = r + 1;
        }
        return ans;
    }
};
```