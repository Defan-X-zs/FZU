#include <stdio.h>//7-5 学生信息输入输出
#include <stdlib.h>
#include <string.h>
struct stud_node 
{
     int num;
     char name[20];
     int score;
     struct stud_node *next;
}*head,*tail;
void input();
int main()
{
    struct stud_node *p; 
    head=tail=NULL;
    input();
    for(p=head;p!=NULL;p=p->next)
    printf("%d %s %d\n",p->num,p->name,p->score);
    return 0;
}
void input()
{
struct stud_node *q;
int score;
char name[20]; 
q=(struct stud_node *)malloc(sizeof(struct stud_node));
scanf("%d",&q->num);
while(q->num!=0)
{
scanf("%s %d",name,&score);
strcpy(q->name,name);
q->score=score;
    q->next=NULL;
if(head==NULL)
{
head=q;
tail=q;
}
else
{
tail->next=q;
} 
tail=q;
q=(struct stud_node *)malloc(sizeof(struct stud_node));
scanf("%d",&q->num);
}
tail->next=NULL;
} 
