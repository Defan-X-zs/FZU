#include<stdio.h>//GCD
int main()
{
    int j,n,m,flag,max=0,a[1000];
    scanf("%d",&n);m=n;
    for(;n>0;n--)
    {
        scanf("%d",&a[n-1]);
        max=(max>a[n-1]?max:a[n-1]);
    }
    for(j=max;j>0;j--)
    {
    flag=0;
         for(n=m;n>0;n--)
         {
            if((a[n-1]%j)!=0)flag=1;
         }
    if(flag==0){printf("%d",j);break;}
    }
    return 0;
}
