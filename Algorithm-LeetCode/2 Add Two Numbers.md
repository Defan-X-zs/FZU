# LeetCode 002
## Add Two Numbers
题目链接：https://leetcode-cn.com/problems/add-two-numbers/

解法1 语言:C 时间复杂度 O( ) 空间复杂度 O( )
```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummy = malloc(sizeof(struct ListNode)), *p = l1, *q = l2, *curr = malloc(sizeof(struct ListNode));
    /*if (l1->val == 0 && l2->val == 0) {
        dummy->val = 0;
        dummy->next = NULL;
        return dummy;
    }*/
    curr = dummy;
    int carry = 0;
    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = sum % 10;     
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }
    curr->next = NULL;
    if (carry) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = carry; 
        curr->next = NULL;
    }
    return dummy->next;
}
```
