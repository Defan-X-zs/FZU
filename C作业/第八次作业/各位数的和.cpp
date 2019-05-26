#include<stdio.h>//各位数的和
int sum(int num)
{
    int a,s=0;
    while(num>0)
    {
    a=num%10;
    s+=a;
    num/=10;
    }
    return s;
}
int main()
{
    int i,num=0,len;
    char a[100];
    gets(a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        num+=a[i]-'0';
    }
    while(num>9){num=sum(num);}
    printf("%d",num);
    return 0;
}
