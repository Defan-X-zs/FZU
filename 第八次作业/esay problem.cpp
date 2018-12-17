#include<stdio.h>//esay problem
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(;m>0;m--)
	{
		scanf("%d%d",&a,&b);
		if(a==1)n+=b;
		if(a==2)n-=b;
		if(a==3)n*=b;
		if(a==4)n/=b;
		if(a==5)n%=b;
	}
 	printf("%d",n);
 	return 0;
} 
