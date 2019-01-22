# LeetCode 014
## Longest Common Prefix
题目链接：https://leetcode-cn.com/problems/longest-common-prefix/
解法1 语言:C 时间复杂度 O(n*m) 空间复杂度 O(1)
```
char* longestCommonPrefix(char** strs, int strsSize) {
    for ( int i = 0; i < strsSize; i++) {
        if (strs[0][0] == '\0') return "";
    }
    if(!strsSize) return "";
    if(strsSize == 1) return strs[0];
    char* prefix = malloc(sizeof(char)*200);
    for(int i=0;i<200;i++)prefix[i] = '\0';
    int i,j;
    for(i = 0;i < strlen(strs[0]); i++) {
        for(j = 0; j < strsSize; j++) {  
            if (strs[0][i] != strs[j][i]) {
                if (!i) return "";
                return prefix;   
            }
        }
        prefix[i] = strs[0][i];
    }
    return prefix;
}
```
