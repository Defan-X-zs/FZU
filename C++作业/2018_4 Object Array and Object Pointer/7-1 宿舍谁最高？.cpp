//7-1 宿舍谁最高？
#include<iostream>
#include<map>
#include<cstring>
using namespace std;

struct node{
	string name;
	int height;
	int weight;
};

int main()
{
	map<int,node>a;
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		int num;
		string str;
		int x,y;
		cin>>num>>str>>x>>y;
		if(a[num].height<x)
		{
			a[num].name=str;
			a[num].height=x;
			a[num].weight=y;
		}
	}
	map<int,node>::iterator it=a.begin();
	for(;it!=a.end();it++)
	{
		printf("%06d",it->first);
		cout<<" "<<it->second.name<<" "<<it->second.height<<" "<<it->second.weight<<endl;
	}
	return 0;
}
 
