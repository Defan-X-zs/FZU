#include<stdio.h>//lucky number
#include<math.h>
int main()
{
    int i,s,sum=0,flag=0,j;
    scanf("%d",&s);
    while(s>0){sum+=s%10;s/=10;}
    j=sqrt(sum);
    for(i=2;i<=j;i++)
    {
        if(sum%i==0)flag=1;
    }
    if(sum==1)flag=1;
    if(flag)printf("So pity, Dao!");
    else printf("Congratulations, Dao!"); 
    return 0;
}
