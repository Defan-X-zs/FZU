#include<stdio.h>//Ï²°®µÄÊý×Ö
int main()
{
    int n,m,a,flag=0,s=0;
    scanf("%d",&a);
    n=a;m=a;
    while(n>0)
    {
        if(n%10==7)flag=1;
        n/=10;
    }
    while(m>0)
    {
        s+=m%2;
        m=(m-m%2)/2;
    }
    if((a%7==0)||flag||(s==0))printf("YES");
    else printf("NO");
    return 0;
}
