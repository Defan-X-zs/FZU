#include<stdio.h>//·ÖÊı¾ØÕó
int main()
{
    double s=0;
    unsigned short i,n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        s=n;
        for(i=2;i<=n;i++)
        {
            s+=(2.0/i)*(n-i+1);
        }
        printf("%.2f\n",s);
    }
    return 0;
}
