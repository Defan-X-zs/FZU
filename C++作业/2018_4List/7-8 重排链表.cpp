#include<stdio.h>//7-8 重排链表
#include<stdlib.h>
#include<string.h>
struct node
{
    int ad,data,next;
}a[100010];
int b[100001],aa[100001];
int main()
{
    int ad,n,i;
    int num = 0;
    int add,data,next;
    scanf("%d %d",&ad,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&add,&data,&next);
        a[add].ad = add;
        a[add].data = data;
        a[add].next = next;
    }
    while(ad!=-1)
    {
        b[num++] = ad;
        ad = a[ad].next;
    }
    int x=0,l=0,r=num-1;
    while(l<=r)
    {
        if(l == r)
            aa[x++] = b[l++];
        else
        {
            aa[x++] = b[r--];
            aa[x++] = b[l++];

        }
    }
    for(i=0;i<x-1;i++)
    {
        printf("%05d %d %05d\n",aa[i],a[aa[i]].data,aa[i+1]);
    }
     printf("%05d %d %d\n",aa[x-1],a[aa[x-1]].data,-1);
     return 0;
}


