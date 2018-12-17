#include<stdio.h>//beautiful number
int main()
{
	int n,a,b,i,j,p=0,q=0;
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{                             
		p=0,q=0;
           scanf("%d %d",&a,&b);
		for(i=1;i<a;i++)
			{if(a%i==0)
			p+=i;} 
		for(i=1;i<b;i++)
			{if(b%i==0)
			q+=i;}	
		if(p==b&&q==a)
		printf("YES");
		else
		printf("NO");
		printf("\n");                       
	}
	return 0;
}
