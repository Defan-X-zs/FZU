#include<stdio.h>//divisorԼ������
#include<math.h>
int main()
{
    long long n,k,sum=0,i=1;
    scanf("%lld",&n);
    k=sqrt(n);
    for(;i<=k;i++)
    {
        if(n%i==0)sum+=2;
        if(n==i*i)sum--;
    }
    printf("%lld",sum);
return 0;
}
