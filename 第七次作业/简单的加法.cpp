#include<stdio.h>//简单的加法
#include<string.h>
int main()
{
    char char_a[1000000],char_b[1000000];
    int num_a[1000000],num_b[1000000];
    int i,j,len_a,len_b,maxlen;
    gets(char_a),gets(char_b);
    len_a=strlen(char_a),len_b=strlen(char_b);
         for(i=0;i<len_a;i++)
         {num_a[i]=char_a[len_a-i-1]-'0';}
         for(i=0;i<len_b;i++)
         {num_b[i]=char_b[len_b-i-1]-'0';}
    maxlen=(len_a>len_b?len_a:len_b);
    for(i=0;i<maxlen;i++)
    {
        num_a[i]+=num_b[i];
        num_a[i+1]+=num_a[i]/ 10;
        num_a[i]%=10;
    }
    if(num_a[i]==0)i--;
    while(i>=0)printf("%d",num_a[i--]);
    return 0;
}
