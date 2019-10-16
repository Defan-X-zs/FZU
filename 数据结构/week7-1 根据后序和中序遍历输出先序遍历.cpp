#include<stdio.h>//7-1 ���ݺ���������������������
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *l,*r;
}*bt;
//�����������������������ؽ���
bt createTree(int *in,int *post,int n){   //ָ��in��postָ���к������ʼλ�ã�n�ǳ���
	if(n<=0)       
	  return NULL;  //�ݹ���ڣ����ؿ�ָ��
	int *p=in;      //p�Ǵ������������ҵ�����λ��
	while(p){
		if(*p==*(post+n-1))
		  break;
		p++;
	}
    int len=p-in;   //���㳤��
	bt t=(bt)malloc(sizeof(struct node));    //��������ڵ㲢��ֵ���ݹ鴴�������Һ���
	t->data=*p;
	t->l=createTree(in,post,len);
	t->r=createTree(p+1,post+len,n-len-1);   //ԭ������Ϊn,��ȥ���������һ�κ͸��ڵ㣬���ȱ�Ϊn-len-1
	return t;
} 
 
void preorder(bt t){                         //����������������õ���������
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
