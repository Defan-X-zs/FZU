#include<stdio.h>//求一分数序列之和 
double sum(int n)
{
	double sum1=0,t,a1,a2;
	a1=1,a2=2;
	for(;n>0;n--)
	{
		sum1+=a2/a1;t=a2;
		a2+=a1;
		a1=t;
	}
	return sum1;
}
int main()
{
	int n;
	scanf("%d",&n); 
 	printf("%.4f",sum(n));
 	return 0;
} 
