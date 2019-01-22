# LeetCode 002
## Add Two Numbers
 [题目链接：https://leetcode-cn.com/problems/add-two-numbers/](https://leetcode-cn.com/problems/add-two-numbers/)
解法1 语言：C 时间复杂度 O(n*n) 空间复杂度 O(1)
```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummy = malloc(sizeof(struct ListNode)), *p = l1, *q = l2;
    int carry = 0;
    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        
    }
    return dummy->next;
}
```
解法2 语言：C 时间复杂度 O(n*n) 空间复杂度 O(1)
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummy = malloc(sizeof(struct ListNode)), *p = l1, *q = l2;
    int carry = 0;
    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        
    }
    return dummy->next;
}
```
