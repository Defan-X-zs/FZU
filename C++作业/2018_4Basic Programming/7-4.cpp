#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{	
	int repeat, l, f;
	char s;
	scanf("%d",&repeat);s = getchar();
	
	while(repeat) {
		l = 0; f = 0;
		{
			while((s = getchar()) != '\n') {
				l++;
				if(l == 1) {
					if((s>='0'&&s<='9')) f = 1;
				}
				else {
					if((s < 'A' && s > '9') || (s < '0') || ((s > 'Z')&&(s != '_')&&(s < 'a')) || (s > 'z')) f++;
				}
			}
			if(f) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
		repeat--;
	}		
}
