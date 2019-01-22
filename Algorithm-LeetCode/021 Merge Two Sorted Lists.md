# LeetCode 021
## Merge Two Sorted Lists
题目链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/
解法1 语言:C 时间复杂度 O(n) 空间复杂度 O(1)
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *tmp, *head;
    head = tmp = (struct LidtNode*)malloc(sizeof(struct ListNode));
    while(1) {
        if (l1 != NULL && l2 != NULL) {
            if (l1->val >= l2->val) {
                tmp->next = l2;
                l2 = l2->next;
                tmp = tmp->next;   
            }
            else {
                tmp->next = l1;
                l1 = l1->next;
                tmp = tmp->next;
            }
        }
        if (l1 != NULL && l2 == NULL) {
            tmp->next = l1;
            return head->next;
        }
        if (l1 == NULL && l2 != NULL) {
            tmp->next = l2;
            return head->next;
        }
        if (l1 == NULL && l2 == NULL) {
            tmp->next = NULL;
            return head->next;
        }
    }
}
```
