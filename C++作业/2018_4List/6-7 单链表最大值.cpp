struct Node* buildLinkedList(int* arr, int n)//6-7 单链表最大值
{
struct Node* abc, *p;
abc = (struct Node*)malloc(sizeof(struct Node));
abc->next = NULL;
for (int i = 0; i < n; i++){
p = (struct Node*)malloc(sizeof(struct Node));
p->data = arr[i];
p->next = abc->next;
abc->next = p;
}
return abc;
}
struct Node* getMax(struct Node* head){
struct Node* p1;
struct Node* p2;
p1 = head->next;
p2 = p1->next;
while(p2)
{
if(p2->data > p1->data)
{
p1 = p2;
p2 = p2->next;
}
else
{
p2 = p2->next;
}
}
return p1;
}

