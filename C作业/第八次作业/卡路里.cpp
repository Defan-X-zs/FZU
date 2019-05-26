#include<stdio.h>//¿¨Â·Àï 
int main()
{
	double L,K,k;
	scanf("%lf %lf",&K,&L); 
	if(L>100)L/=1000;
	k=K*L*1.036;
 	printf("%.2f",k);
 	return 0;
} 
