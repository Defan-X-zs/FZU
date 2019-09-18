//堆栈操作合法性
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n, m;
	int len, ssum, xsum;
	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		char t[100];
		int flag=1;
		cin>>t;
		len = strlen(t);
		ssum=0,xsum=0;
		for(int j=0;j < len; j++)
		{
			if(t[j]=='S') ssum++;
			else if(t[j]=='X') xsum++;
			if(ssum<xsum) {flag=0;break;}
			if(ssum-xsum>m) {flag=0;break;}
		}
		if(ssum!=xsum) flag=0;
		if(flag) puts("YES");
		else puts("NO");
	}
}
