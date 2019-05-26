#include<stdio.h>//ÏÌÓã·­Éí
int main()
{
unsigned int i,n,m,sum=0,s;
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)
{
	scanf("%d",&s);sum+=s;
}
if(m%2==0)printf("%d",sum);
else printf("%d",n-sum);
return 0;
}
