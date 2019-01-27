# LeetCode 019
## Remove Nth Node From End of List
题目链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
解法1 语言:C 时间复杂度 O(L) 空间复杂度 O(1)
```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *fast, *slow, *dummyHead;
    fast = slow = dummyHead = malloc(sizeof(struct ListNode));
    fast->next = slow->next = dummyHead->next = head;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    for(int i = n; fast->next != NULL; i++) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummyHead->next;
}
```