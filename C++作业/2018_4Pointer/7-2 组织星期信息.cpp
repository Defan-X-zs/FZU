#include <iostream> //7-2 组织星期信息
#include <string>

using namespace std;

int getindex( string s )
{
	int i;
	string week[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	for (i = 1; i <= 7; i++)
	{
		if (s == week[i-1]) break;
	}
	if (i == 8) i = -1;
	return i;
}

int main()
{
	int repeat;
	string s;
	cin>>repeat;
	while(repeat--) {
		cin>>s;
		cout<<getindex(s)<<endl;
	}
}
