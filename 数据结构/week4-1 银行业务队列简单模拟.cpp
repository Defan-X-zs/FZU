#include<iostream>//7-1 银行业务队列简单模拟	
#include<queue>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int t;
	queue<int> a, b;
	for(int i = 0; i < n; i++)
	{
		cin>>t;
		if(t%2==1)//奇数
		{
			a.push(t);
		} 
		else
		{
			b.push(t);
		}
	}
	n--;
	while(!a.empty()||!b.empty())
	{
		if(!a.empty()) 
		{
			cout<<a.front();
			a.pop();
			if(n){cout<<" ";n--;}
		}
		if(!a.empty()) 
		{
			cout<<a.front();
			a.pop();
			if(n){cout<<" ";n--;}
		}
		if(!b.empty()) 
		{
			cout<<b.front();
			b.pop();
			if(n){cout<<" ";n--;}
		}
	}
}
