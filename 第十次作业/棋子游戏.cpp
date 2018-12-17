#include<stdio.h>//фЕвссно╥
int main()
{
    unsigned int a[1000]={0},n=0,i=1,l,r,max=0,sum=0;
    scanf("%d",&n);
    for(;i<=n;i++)
    {
        scanf("%d",&a[i]);
  a[i]+=a[i-1];
    }
    for(l=1;l<=n;l++)
    {
        for(r=l;r<=n;r++)
        {
            sum=0;
            sum=a[l-1]+r-l+1-(a[r]-a[l-1])+a[n]-a[r];
            max=(max>sum?max:sum);
        }
    }
    printf("%d",max);
return 0;
}
