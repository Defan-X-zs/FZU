//7-1 �����������������������
#include<iostream>
#include<stdio.h>
using namespace std; 
struct treenode
{
    treenode *l,*r,*f;
    int data;
};
int a[10001];
int b[10001];
treenode *create(int l,int r)
{
    if(l>r)
        return NULL;
    treenode *root=new treenode;
    root->data=a[l];
    root->f=NULL;
    root->l=root->r=NULL;
    int i;
    for(i=l+1; i<=r; i++)//���ݶ��������������ʽ�������һ�����ڵ��ڸ��ڵ�İ��������Ŀ϶�����������������������
    {
        if(a[i]>=a[l])
            break;
    }
    root->l=create(l+1,i-1);
    if(root->l)//Ҫ�����Ƿ�Ϊ��
        root->l->f=root;//���father�ڵ�
    root->r=create(i,r);
    if(root->r)
        root->r->f=root;
    return root;
}

int Find(treenode *root,int x)//����rootΪ�����������Ƿ���ҵ�x
{
    if(root)
    {
        if(root->data==x)
            return 1;
        if(x<root->data)
            return Find(root->l,x);
        else
            return Find(root->r,x);
    }
    return 0;
}
int Find_F(treenode *root,int u,int v)//u�Ƿ���v������
{
    if(root)
    {
        if(root->data==u)
        {
            if(Find(root,v))//�����u���������ҵ���v����˵��u��v������
                return 1;
            return 0;
        }
        if(u<root->data)
            return Find_F(root->l,u,v);
        else
            return Find_F(root->r,u,v);
    }
    return 0;
 
}
int Find_LCA(treenode *root,int x)//�ӵ�һ���ڵ�ĵ�ַ�����ҵڶ����ڵ������
{
    while(root->f)
    {
        root=root->f;
        int r=Find(root,x);
        if(r)       //���ҵ������ض�Ӧ���Ƚڵ�ֵ
            return root->data;
    }
    return 0;
}
treenode *Find_POS(treenode *root,int x)//�ҵ�һ���ڵ��λ�ã����ص���һ��ָ��
{
    if(root)
    {
        if(root->data==x)
            return root;
        if(x<root->data)
            return Find_POS(root->l,x);
        else
            return Find_POS(root->r,x);
    }
    return NULL;
}
 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    treenode *root=NULL;
    for(int i =0;i<10001;i++) b[i]=0;
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;//�����ǣ����Ƿ�������
    }
    root=create(1,m);
    for(int i=1; i<=n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(!b[u]&&!b[v])//��������ģ�⼴��
            cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
        else if(!b[u])
            cout<<"ERROR: "<<u<<" is not found."<<endl;
        else if(!b[v])
            cout<<"ERROR: "<<v<<" is not found."<<endl;
        else
        {
            int x=Find_F(root,u,v);
            int y=Find_F(root,v,u);
            if(x)
                cout<<u<<" is an ancestor of "<<v<<"."<<endl;
            else if(y)
                cout<<v<<" is an ancestor of "<<u<<"."<<endl;
            else
            {
                treenode *temp=Find_POS(root,u);//���ѡһ�����ܹ��������ж�˭��˭����
                int r=Find_LCA(temp,v);
                cout<<"LCA of "<<u<<" and "<<v<<" "<<"is"<<" "<<r<<"."<<endl;
            }
 
        }
    }
    return 0;
}
