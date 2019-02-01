# LeetCode 203
## Remove Linked List Elements
题目链接：https://leetcode-cn.com/problems/remove-linked-list-elements/
解法1 语言:C 时间复杂度 O(n) 空间复杂度 O(1)
```
struct ListNode* removeElements(struct ListNode* head, int val) {
    if ( !head) return NULL;
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy = head;
    while (dummy->next) {
        if (dummy->next->val == val) {
            dummy->next = dummy->next->next;
        }
        else
        dummy = dummy->next;
    } 
    if (head->val == val) {
        head = head->next;    
    }
    return head;
}
```