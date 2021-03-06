# LeetCode 013
## Roman To Integer
题目链接：https://leetcode-cn.com/problems/roman-to-integer/
解法1 语言:C 时间复杂度O( ) 空间复杂度 O(1)
```
int romanToInt(char* s) {
    int i = 0, num = 0;
    for(; i < strlen(s); i++) {
        if ((*(s + i) == 'I' ||*(s + i) == 'X' ||*(s + i) == 'C') && *(s + i + 1) != '\0') {
            if(*(s + i) == 'I') {
                if(*(s + i + 1) == 'V') num += 4, i++;
                else if(*(s + i + 1) == 'X') num += 9,printf("%d ",num), i++;
                else num += 1;  
                continue;
            }
            if(*(s + i) == 'X') {
                if(*(s + i + 1) == 'L') num += 40, i++;
                else if(*(s + i + 1) == 'C') num += 90, i++;
                else num += 10;
                continue;
            }
            if(*(s + i) == 'C') {
                if(*(s + i + 1) == 'D') num += 400, i++;
                else if(*(s + i + 1) == 'M') num += 900, i++;
                else num += 100;
                continue;
            }
        }
        else {
        if(*(s + i) == 'I') num += 1;
        if(*(s + i) == 'V') num += 5;
        if(*(s + i) == 'X') num += 10;
        if(*(s + i) == 'L') num += 50;
        if(*(s + i) == 'C') num += 100;
        if(*(s + i) == 'D') num += 500;
        if(*(s + i) == 'M') num += 1000;
        }
    }
    return num;
}
```
解法2 语言:C++ 时间复杂度O(s) 空间复杂度 O(1)
```
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        map<char, int> roman_num_map;
        roman_num_map['I'] = 1;
        roman_num_map['V'] = 5;
        roman_num_map['X'] = 10;
        roman_num_map['L'] = 50;
        roman_num_map['C'] = 100;
        roman_num_map['D'] = 500;
        roman_num_map['M'] = 1000;
        
        int size = s.size();
        for(int i = 0; i < size; i++)
        {
            //小的数字位于大的数字左边
            if(roman_num_map[s[i]] < roman_num_map[s[i + 1]])
            {
                result -= roman_num_map[s[i]];
            }
            else
            {
                 result += roman_num_map[s[i]];
            }         
        } 
        return result;
    }
};
```
