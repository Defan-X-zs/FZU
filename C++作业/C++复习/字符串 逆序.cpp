#include<string.h>//说反话
#include<iostream>
using namespace std;
int main()
{ 
	char s[80];
	int i;
	gets(s);
	for (i=strlen(s)-1;i>0;i--) 
		if (s[i]==' ') 
		{ 
			cout<<&s[i+1]<<" "; 
			s[i]='\0';
		}
	cout<<s;
}
