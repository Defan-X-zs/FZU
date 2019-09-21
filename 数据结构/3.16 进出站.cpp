#include<iostream>//3.16 进出站
#include<stack>
using namespace std; //有bug 如54321不可用 
int main()
{
	int n;
	cin>>n;
	int a[n], res[n], tmp, i, k=0;
	stack<int> s;
	for(i = 1; i <= n; i++)
	{
		cin>>tmp;//cout<<tmp<<endl;
		if(tmp==n)
		{
			res[k++] = tmp;
			//cout<<res[0];
			break;
		}
		else
		{
			s.push(tmp);
		}
	}
	//cout<<"i="<<i<<endl;
	if(i<n){cin>>tmp;}
	for(int j = i; 1; j++)
	{
		//cout<<"s"<<j;
		//cout<<"size "<<s.size()<<"k "<<k<<endl;
		if(s.size() + k == n){break;}
			{
				if(!s.empty() && tmp > s.top())
				{
					res[k++] = tmp;
					if(s.size() + k == n){break;}
					else cin>>tmp;
				}
				else
				{
					if(s.size() + k == n)break;
					if(k == n-1){res[k++]=tmp;break;}
					res[k++] = s.top();
					s.pop();
				}
			}
	}
	if(!s.empty())
	{
		//cout<<"op1 ";
		for(i = 0; i < k; i++)cout<<res[i]<<" ";
		for(; i < n-1; i++)
		{
			cout<<s.top()<<" ";
			s.pop();	
		}
		cout<<s.top();
		s.pop(); 
	}
	else
	{	int j;
		for(j = 0; j < n-1; j++)
		{
			cout<<res[j]<<" ";
		}
		cout<<res[j];
	}
}
