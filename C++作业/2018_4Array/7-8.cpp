#include <stdio.h>//7-8 将下标为偶数的元素值赋值给数组n 
int main()
{
	int a[10],n[5], i, j; 
	for(i=0;i<10;i++) {
		scanf("%d", &a[i]);
	}
	for(i=0,j=0;i<10;i+=2,j++)
	{
		n[j]=a[i];
	}
	for(j=0;j<5;j++) printf("   %d", n[j]);
	return 0;
} 
