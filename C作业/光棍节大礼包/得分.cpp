#include<stdio.h>//ตรทึ 
int main()
{
	int n,i;
	float a,max=0,min=101,avg=0;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
		scanf("%f",&a);
    	max=(a>max?a:max);
    	min=(a<min?a:min);
    	avg+=a;
	}
	avg-=(max+min);
	avg/=n-2;
 	printf("%.1f",avg);
 	return 0;
}
