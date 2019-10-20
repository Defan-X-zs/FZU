#include<stdio.h>//7-1 根据后序和中序遍历输出先序遍历
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *l,*r;
}*bt;
//根据输入的中序后序排列来重建树
bt createTree(int *in,int *post,int n){   //指针in和post指向中后序的起始位置，n是长度
	if(n<=0)       
	  return NULL;  //递归出口，返回空指针
	int *p=in;      //p是从中序排列中找到根的位置
	while(p){
		if(*p==*(post+n-1))
		  break;
		p++;
	}
    int len=p-in;   //计算长度
	bt t=(bt)malloc(sizeof(struct node));    //创建这个节点并赋值，递归创建其左右孩子
	t->data=*p;
	t->l=createTree(in,post,len);
	t->r=createTree(p+1,post+len,n-len-1);   //原来长度为n,减去左边子树的一段和根节点，长度变为n-len-1
	return t;
} 
 
void preorder(bt t){                         //先序遍历创建的树得到先序排列
	if(t){
		printf(" %d",t->data);
		preorder(t->l);
		preorder(t->r);
	}
}
 
int main(){
	int n,in[50],post[50];
	bt t;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&post[i]);
	for(int i = 0;i < n;i++)
		scanf("%d",&in[i]);
    t=createTree(in,post,n);
    printf("Preorder:");
    preorder(t);
    return 0;
}
