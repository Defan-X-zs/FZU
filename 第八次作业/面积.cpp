#include<stdio.h>//Ãæ»ý
#include<math.h> 
int main()
{
    double x1,x2,x3,x4,y1,y2,y3,y4;
    double p1,p2,a,b,c,d,e,s1,s2,s;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    a=sqrt((y4-y1)*(y4-y1)+(x4-x1)*(x4-x1));
    b=sqrt((y4-y3)*(y4-y3)+(x4-x3)*(x4-x3));
	c=sqrt((y3-y2)*(y3-y2)+(x3-x2)*(x3-x2));
	d=sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
	e=sqrt((y3-y1)*(y3-y1)+(x3-x1)*(x3-x1));
	p1=0.5*(a+b+e);
	p2=0.5*(c+d+e);
	s1=sqrt(p1*(p1-a)*(p1-b)*(p1-e));
	s2=sqrt(p2*(p2-c)*(p2-d)*(p2-e));
	s=s1+s2;
 	printf("%.2f",s);
 	return 0;
}
