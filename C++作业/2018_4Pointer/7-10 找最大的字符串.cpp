#include <stdio.h>//7-10 找最大的字符串
int main()
{
	char c,str[10][100];
	int s,max,k;
	int i,n;
	max=0;
	for(i=0;i<10;i++)
	{
		s=0;
		n=0;
		while((c=getchar())!='\n')
		{
			str[i][n++]=c;
			s+=(int)c;
		}
		str[i][n]='\0';
		if(max<s)
		{
			max=s;
			k=i;
		}
	}
	printf("Max is: %s\n",str[k]);
}
