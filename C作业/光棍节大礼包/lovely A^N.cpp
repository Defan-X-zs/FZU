#include<stdio.h>//lovely A^N
int main()
{
	int a,n,s=1;
	while(scanf("%d%d",&a,&n)!=EOF && (a||n))  
	{
           a%=1000;
		for(;n>0;n--)
		{				
				s=s*a;
				s%=1000;
		}
		printf("%d\n",s);
           s=1;
     }
	return 0;
}
