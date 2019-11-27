#include<iostream>//8.4 石子合并问题
#include<queue>
using namespace std;
int main()
{
		int n, a;
		cin>>n;
		priority_queue<int, vector<int>, greater<int> >q;
		for(int i=0; i<n; i++)
		{
			cin>>a;
			q.push(a);
		}
		int sum=0;
		while(q.size() > 1)
		{
			int min1 = q.top();
			q.pop();
			int min2 = q.top();
			q.pop();
			sum += (min1+min2);
			q.push(min1+min2);
		}
		cout<<sum<<endl;
		return 0;
} 
