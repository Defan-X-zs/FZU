#include<stdio.h>//7-3 单向链表5
#include<stdlib.h>
#include<string.h>
struct stud_node{
int num;
char name[20];
int score;
struct stud_node *next;      /*定义结构类型变量 stud_node为全局变量*/
};
struct stud_node *Creat_Stu_Doc();
struct stud_node *DeleteDoc(struct stud_node *head,int min_score);
void Ptrint_Stu_Doc(struct stud_node *head);
void main()
{
struct stud_node *head;
int min_score;

head=Creat_Stu_Doc();
scanf("%d",&min_score);
head=DeleteDoc(head,min_score);
Ptrint_Stu_Doc(head);
}
struct stud_node *Creat_Stu_Doc()
{
struct stud_node *head,*tail, *p;
int num, score;
char name[20];
int size = sizeof(struct stud_node);

head=tail=NULL;
scanf("%d",&num);
while(num != 0){
scanf("%s%d",name,&score);
p=(struct stud_node*)malloc(size);
p->num=num;
strcpy(p->name,name);
p->score=score;
p->next=NULL;
if(head==NULL)
head=p;
else
tail->next=p;
tail=p;
scanf("%d",&num);
}
return head;
}
struct stud_node *DeleteDoc(struct stud_node *head,int min_score)
{
struct stud_node*ptr1,*ptr2;

while(head!=NULL&&head->score<min_score){
ptr2=head;
head=head->next;
free(ptr2);
}
if(head==NULL)
return NULL;
ptr1=head;
ptr2=head->next;
while(ptr2!=NULL){
if(ptr2->score<min_score){
ptr1->next=ptr2->next;
free(ptr2);
}
else
ptr1=ptr2;
ptr2=ptr1->next;
}    
return head;
}
void Ptrint_Stu_Doc(struct stud_node *head)
{
struct stud_node*ptr;

if(head==NULL){
printf("\nNo Records\n");
return;
}
for(ptr=head; ptr; ptr=ptr->next)  
printf("%d %s %d\n", ptr->num,ptr->name,ptr->score);
}
