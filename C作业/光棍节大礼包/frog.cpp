#include<stdio.h>//frog
int main()
{
	int n,i,sum=0;
    scanf("%d",&n);
    for(i=1;sum<n;i++)
    {
    	sum=sum+i;
    }
    i-=1;
    printf("%d",i);
    return 0;
}
