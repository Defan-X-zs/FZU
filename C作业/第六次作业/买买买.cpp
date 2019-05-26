#include<stdio.h>//ÂòÂòÂò
int main()
{
	unsigned int a[29800]={0},sum[7940],n,i=1,q,l,r;
scanf("%d%d",&n,&q);
for(;i<=n;i++)
{
	scanf("%d",&a[i]);
	a[i]+=a[i-1];
}
for(i=1;i<=q;i++)
{
scanf("%d%d",&l,&r);
sum[i]=a[r]-a[l-1];
}
for(i=1;i<=q;i++)printf("%d\n",sum[i]);
return 0;
}
