#include<stdio.h>//½â·½³Ì
#include<math.h>
int main()
{   
	double a,b,c,i,j,x1,x2,t;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a==0&&b==0)printf("No,answer!");
    else if(a==0)printf("%.2f",-c/b);
    else if(b*b-4*a*c<0)printf("No,answer!");
	else if(b*b-4*a*c==0)printf("%.2f",-b/a/2);
    else 
	{
	x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	if(x1>x2)t=x1,x1=x2,x2=t;
	printf("%.2f %.2f",x1,x2);
    }
 	return 0;
}
