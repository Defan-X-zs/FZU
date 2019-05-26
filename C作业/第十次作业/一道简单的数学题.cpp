#include<stdio.h>//一道简单的数学题
int main()
{
    int p,a,b,flag=0;
    scanf("%d",&p);
    for(a=1000;a>0;a--)
    {
        for(b=1;b<1000;b++)
        {
            if(a*a*a-b*b*b==p){flag=1;break;}
        }
    }
    if(flag)putchar('Y'),putchar('E'),putchar('S');
    else putchar('N'),putchar('O'); 
    return 0;
}
