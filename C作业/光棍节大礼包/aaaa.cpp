#include<stdio.h>//aaaa
#include<math.h>
int main()
{
	int n,i;
	float a,j,sum=0,c=0;
	scanf("%f%d",&a,&n);
	for(i=1;i<=n;i++)
	{
		c=0;
		for(j=0;j<i;j++)
		{
			c+=a*pow(10.0,j);
		}
		sum+=c;
	}
		printf("%.0f",sum);
	return 0;
}
