#include<stdio.h>//±ùä¿ÁèÇò 
#include<math.h>
int main()
{
	int n,i,j;
	double a[1000],pi,r,x;
	scanf("%d",&n);
	pi=acos(-1.0);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&r);
		a[i]=4.0*pi*r*r*r/3.0; 
	} 
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-j;i++)
		{
			if(a[i]<a[i+1])
			{
				x=a[i];
				a[i]=a[i+1];
				a[i+1]=x;
			}
		}
	}
	for(i=0;i<n;i++)printf("%.2f\n",a[i]);
	return 0;
}
