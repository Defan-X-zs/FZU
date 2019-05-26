#include<stdio.h>//power A^B
unsigned int sum(unsigned int c)
{
unsigned int s=0,a;
while(c>0)
{
a=c%10;
s+=a;
c/=10;
}
return s;
}
int main()
{
  unsigned int c,a,b,i;
  scanf("%d%d%d",&c,&a,&b);
  for(i=b;i>0;i--)
  {
  c*=a;c=sum(c);
  }
  c=sum(c);
  printf("%d",c);
return 0;
}
