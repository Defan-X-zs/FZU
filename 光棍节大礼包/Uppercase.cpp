#include<stdio.h>//Uppercase
int main()
{
	char str[100];
	int n=1;
	gets(str);
	if(str[0]>='a'&&str[0]<='z')str[0]-=32;
	while(str[n]!='\0')
	{
		if(str[n-1]==' '&&str[n]>='a'&&str[n]<='z') str[n]-=32;
		else if(str[n-1]!=' '&&str[n]>='A'&&str[n]<='Z') str[n]+=32;
		n++;
	}
	puts(str);
return 0;
}
