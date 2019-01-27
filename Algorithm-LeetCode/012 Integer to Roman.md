# LeetCode 012
## Integer to Roman
题目链接：https://leetcode-cn.com/problems/integer-to-roman/
解法1 语言:C 时间复杂度 O( ) 空间复杂度 O(1)
```
char* intToRoman(int num) {
    char *res;
    res = malloc(sizeof(char) * 20);
    int j = 0, i = 0;
    if(num >= 1000) {
        int tmp = num / 1000;
        for(i = 0; i < tmp; i++) res[j++] = 'M';
        num -= tmp * 1000;
    }
    if(num >= 900) {
        res[j++] = 'C', res[j++] = 'M';
        num -= 900;
    }
    if(num >= 500) {
        res[j++] = 'D';
        num -= 500;
    }
    if(num >= 400) {
        res[j++] = 'C', res[j++] = 'D';
        num -= 400;
    }
    if(num >= 100) {
        int tmp = num / 100;
        for(i = 0; i < tmp; i++) res[j++] = 'C';
        num -= tmp * 100;
    }
    if(num >= 90) {
        res[j++] = 'X', res[j++] = 'C';
        num -= 90;
    }
    if(num >= 50) {
        res[j++] = 'L';
        num -= 50;
    }
    if(num >= 40) {
        res[j++] = 'X', res[j++] = 'L';
        num -= 40;
    }
    if(num >= 10) {
        int tmp = num / 10;
        for(i = 0; i < tmp; i++) res[j++] = 'X';
        num -= tmp * 10;
    }
    if(num >= 9) {
        res[j++] = 'I', res[j++] = 'X';
        num -= 9;
    }
    if(num >= 5) {
        res[j++] = 'V';
        num -= 5;
    }
    if(num >= 4) {
        res[j++] = 'I', res[j++] = 'V';
        num -= 4;
        }
    if(num >= 1) {
        int tmp = num / 1;printf("%d",res[j]);
        for(i = 0; i < tmp; i++) res[j++] = 'I';
    }
    res[j] = '\0';   
    return res;
    
}
```