# LeetCode 001
## Add Two Numbers
题目链接：https://leetcode-cn.com/problems/two-sum/

解法1 语言:C 时间复杂度 O(n*n) 空间复杂度 O(1)
```
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int* a = malloc(sizeof(int)*2);//分配动态内存
    for(i = 0; i < numsSize - 1; i++) {
        for(j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                a[0] = i;
                a[1] = j;
            }
        }
    }
    return a;
}
```
解法2 语言:C++ 时间复杂度 O(n) 空间复杂度 O(n)
```
class Solution { 
    public: 
    vector<int> twoSum(vector<int>& nums, int target) { 
        vector<int> res; 
        map<int ,int> map ;
        int key, tmp, numsSize = nums.size();
        for (int i = 0; i < numsSize ; i++) { 
            key = target - nums[i];
            map[key] = i;
        } 
        for (int i = 0; i < numsSize ; i++) { 
            tmp = nums[i];
            if(map.count(tmp) && i != map[tmp]) {
                res.push_back(i); 
                res.push_back(map[tmp]); 
                return res; 
            } 
        } 
        return res; 
    }
};
```

