#include <stdio.h>//7-6 使用函数实现字符串复制
#include <string.h>

void strmcpy( char *s, char *t, int m )
{	
	int i = m-1, j = 0;
	while(t[i]!='\0') {
		s[j++] = t[i++];
	}
	s[j]='\0';
}

int main()
{
	int repeat, m, j;
	char t1[100], s1[100];
	scanf("%d", &repeat);
	getchar(); 
	for(j = 0; j < repeat; j++) {
		gets(t1);
		scanf("%d",&m);
		getchar();
		if(strlen(t1)<m) {
			printf("error input");
		}
		else {
			strmcpy( s1, t1, m);
			puts(s1);
		}
	}
}
