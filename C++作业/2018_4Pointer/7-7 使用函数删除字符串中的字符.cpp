#include <stdio.h>//7-7 使用函数删除字符串中的字符

void delchar(char *str, char c )
{	
	int i, j, cout = 0;
	while(str[i]!='\0') {
		if(str[i]!=c) {
			str[j++] = str[i];
		}
		i++;
	}
	str[j] = '\0';
}

int main()
{
	int i=0, repeat, n;
	char a[100], e;
    scanf("%d", &repeat);getchar();
    while(repeat--) {
    	gets(a);
		e = getchar();
    	delchar(a, e);
    	printf("result: %s\n", a);
    }
}
