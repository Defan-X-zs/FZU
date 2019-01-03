#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,i,m;
	scanf("%d",&n);
	for(m=1,i=0;n>m;i++)
	{
		m*=2;
	}
	printf("%d",i);
return 0;
}
