#include <stdio.h>//7-2 单向链表4
#include <stdlib.h>
typedef int ElemType;//声明定义数据类型为整型 
typedef struct Node//定义节点 
{
	ElemType data;
	struct Node *next;
} Node;
typedef struct Node *LinkList;//定义LinkList 

void CreateListHead(LinkList *L);
void PrintList(LinkList *L);

int main(int argc, char *argv[]) {
	LinkList list1;//声明一个链表list1 
	CreateListHead(&list1);//生成链表（头插法） 
	PrintList(&list1);//打印链表 
	return 0;
}
/*创建链表符合题目的链表，带头结点，使用头插法*/
void CreateListHead(LinkList *L)
{
	LinkList p;
	int number;
	*L=(LinkList)malloc(sizeof(Node));//生成头节点 
	(*L)->next=NULL;
	do
	{
		scanf("%d",&number);
		if(number!=-1)
		{
			p=(LinkList)malloc(sizeof(Node));//生成一个新的节点 
			p->data=number;
			p->next=(*L)->next;//将*L的后继赋值给p的后继 
			(*L)->next=p;//将p赋值给*L的后继 
		}	
	}while(number!=-1);//当number等于-1退出循环 
}

void PrintList(LinkList *L)
{
	LinkList p;
	for(p=(*L)->next;p->next!=NULL;p=p->next)//循环遍历打印最后一个节点之前的元素，因为链表list1有头结点所以p的初始值为(*L)->next，既第一元素节点 
	{
		printf("%d ",p->data);
	}
	printf("%d\n",p->data);//因为要求打印最后一个元素后不带空格，所以单独打印 
}
