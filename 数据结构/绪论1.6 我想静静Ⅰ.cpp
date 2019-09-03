//绪论1.6 我想静静Ⅰ
#include<iostream>
using namespace std;
int main()
{
	int n,num,onlynum = 0;
	cin>>n;
	for(int i=0; i < n; i++)
	{
		cin>>num;
		onlynum = onlynum ^ num; //通过异或实现找出仅出现一次的数值
	}
	cout<<onlynum;
	return 0;
}