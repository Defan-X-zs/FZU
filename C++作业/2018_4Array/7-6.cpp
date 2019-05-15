#include <stdio.h>//7-6 输出小于均值的数
int main()
{
	int a[10], sum=0, avg, i; 
	for(i=0;i<10;i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	avg = sum/10;
	for(i=0;i<10;i++)
	{
		if(a[i]<avg) printf("%d ",a[i]);
	}
	return 0;
} 
