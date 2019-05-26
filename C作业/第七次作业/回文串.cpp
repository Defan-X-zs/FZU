#include<stdio.h>//»ØÎÄ´®
int main()
{
unsigned int i;
char a[999];
gets(a);
for(i=3;;i++)
{
	if((a[i-1]==a[i+1])&&(a[i-2]==a[i+2])&&(a[i-3]==a[i+3]))
	{
	putchar(a[i-3]),putchar(a[i-2]),putchar(a[i-1]),putchar(a[i]),putchar(a[i+1]),putchar(a[i+2]),putchar(a[i+3]),putchar('\n');
	}
	if(a[i+4]=='\0')break;
}
return 0;
}
