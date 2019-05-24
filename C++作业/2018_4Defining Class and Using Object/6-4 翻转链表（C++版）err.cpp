//6-4 翻转链表（C++版）
ListNode *reverse(ListNode *head) {
        ListNode* pCurrent=head;
        ListNode* pRet=NULL;
        while(pCurrent) {
            head=head->next;
            pCurrent->next=pRet;
            pRet=pCurrent;
            pCurrent=head;
        }
        return pRet;
    }
 /*
 * 数组arr存储创建链表用的数据，n为数组长度。
 * 函数返回值为创建的新链表的头指针。
 */
ListNode* buildList(int* arr,int n) {
	ListNode* dummy = new ListNode(0);
	ListNode* temp1 = new ListNode(arr[0]);
	dummy->next = temp1;
	for(int i = 1; i < n-1; i++) {
		ListNode* temp1 = new ListNode(arr[i]);
		
	}
	return dummy;
}

 /*
 * 打印链表，数据间用一个空格分隔，最后一个数据后面
 * 没有多余的空格。如果链表为空，则直接打印NULL。
 */
void printList(ListNode* head) {
	if(head->next == NULL) {
		cout<<"NULL";
	}
	else {
		while(head->next != NULL) {
			head = head->next;
			cout<<head->val;
			if(head->next != NULL) {
				cout<<" ";
			}
		}
	}
}
