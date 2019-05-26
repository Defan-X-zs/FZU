#include<stdio.h>//≈∆√Ê¿€º”
int main()
{
	int n,i,m=0,q=0;
	scanf("%d",&n);
	int a[1001],b[1001];
	for(i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
		m+=a[i];
	}
		for(i=0;i<=n;i++)
	{
		scanf("%d",&b[i]);
		q+=b[i];
	}
	if(m>q)
	printf("cat");
	else if(m<q)
	printf("pig");
	else
	printf("sad");
	return 0;
}
