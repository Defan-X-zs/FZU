#include<stdio.h>//7-1 单向链表3
#include<stdlib.h>
#include<string.h>
struct number *new_point();
void fact(struct number *head,int n,int x);
struct number{
	int num;
	struct number *next;
};
int main(){
	int i,j,repeat,n,x;
	struct number *head,*p,*q;
	if((head=(struct number * )malloc (sizeof(struct number)))==NULL)
	{
		printf("Error!\n");
		exit(0);
	}
	head->num=-1;
	head->next=NULL;
	scanf("%d",&repeat);
	for(i=0;i<repeat;i++){
		scanf("%d",&n);
		q=head;
		for(j=0;j<n;j++){
			p=new_point();
			q->next=p;
			q=p;
			scanf("%d",&(p->num));
		}
		scanf("%d",&x);
		fact(head,n,x);
	}
}
struct number *new_point(){
	struct number *p;
	if((p=(struct number * )malloc (sizeof(struct number)))==NULL){
		printf("Error!\n");
		exit(0);
	}
	p->num=-1;
	p->next=NULL;
	return p;
}
void fact(struct number *head,int n,int x){
	struct number *p,*q;
	int i;
	q=new_point();
	for(p=head->next;p!=NULL;p=p->next){
		if(x<=head->next->num){
			q->next=head->next;
			head->next=q;
			q->num=x;
			break;
		} 
		if((p->next==NULL)&&((p->num)<x)){
		  p->next=q;
		  q->num=x;
		  break;
		}
		if((p->num<x)&&(p->next->num>=x)){
			q->next=p->next;
			p->next=q;
			q->num=x;
			break;
		}
	}
	printf("size=%d:",n+1);
	for(p=head->next;p!=NULL;p=p->next){
		if(p==head->next) printf("%d",p->num);
		else printf(" %d",p->num);
	}
	printf("\n");
}
