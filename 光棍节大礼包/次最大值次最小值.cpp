#include<stdio.h>//次最大值次最小值 
int main()
{
	int n,i,j,x;
	int a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
		}
	}n=n-2;
	printf("%d ",a[1]);
	printf("%d",a[n]);
	return 0;
}
