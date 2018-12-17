#include<stdio.h>//·Ö¶Îº¯Êý 
#include<math.h>
int main()
{
	int t,n,m;
	int f(int n,int m);
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",f(n,m));
		t--;
	}
	return 0;
}
int f(int n,int m)
{
	if(n==0&&m==0)return 1;
	else if(n==0&&m!=0)return m;
	else if(n!=0&&m==0)return n;
	else if(m%2==1)return n*m+f(n,floor(m/2));
	else return n*m+f(m,floor(n/2));
}
