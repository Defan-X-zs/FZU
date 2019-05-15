#include<stdio.h>//7-2 找出3个字符串中最大的字符串
#include<string.h>
int main()
{
    char a[3][20],string[20];
    int i;
    for(i=0;i<3;i++)
    scanf("%s",a[i]);
        
    printf("The largest string is:\n");
    if(strcmp(a[0],a[1])>0) strcpy(string,a[0]);
    else strcpy(string,a[1]);
    
    if(strcmp(string,a[2])>0) printf("%s",string);
    else printf("%s",a[2]);
    return 0;
}

