#include<stdio.h>//¼òµ¥µÄÓÎÏ·
int main()
{
int n;
scanf("%d",&n);
int i=1,a[1000]={0},sumb=0,sumc=0,max=0,maxn,b,c;
for(;i<=n;i++)
{
	if(i%2!=0)scanf("%d",&b),sumb+=b;
	else
	{
		scanf("%d",&a[i]);
		sumc+=a[i];
		if(a[i]>max)max=a[i],maxn=(i+1)/2;
	}
	
}
if(sumb>sumc-max)printf("%d",maxn);
else printf("RUN");
return 0;
}
