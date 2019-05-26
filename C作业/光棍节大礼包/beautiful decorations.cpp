#include<stdio.h>//beautiful decorations 
int main()
{
    int i,j,k,n;
    char e;
    scanf("%d %c",&n,&e);
    for(i=n;i>0;i--)
    {
        for(j=0;j<2*n-1;j++)putchar(' ');
        printf("%c\n",e);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<2*n-1-i;j++)putchar(' ');
        for(k=0;k<i+1;k++)printf("%d",k+1);
        for(k=k-1;k>0;k--)printf("%d",k);
        putchar('\n');
    }
    for(i=0;i<n;i++)printf("%c",e);
    {
        for(k=0;k<i;k++)printf("%d",k+1);
        for(k=k-1;k>0;k--)printf("%d",k);
    }
    for(k=0;k<i;k++)printf("%c",e);putchar('\n');
    for(i=n-1;i>0;i--)
    {
        for(j=0;j<2*n-i;j++)putchar(' ');
        for(k=0;k<i;k++)printf("%d",k+1);
        for(k=k-1;k>0;k--)printf("%d",k);
        putchar('\n');
    }
    for(i=n;i>0;i--)
    {
        for(j=0;j<2*n-1;j++)putchar(' ');
        printf("%c\n",e);
    }
    return 0;
}

