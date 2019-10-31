#include<iostream>//7-1 …Ó»Îª¢—®
#include<vector>
using namespace std;
vector<int>pre[100001];
vector<int>door;
int entrance, depth=0, location=0;
void dfs(int n, int deep)
{
        if(pre[n].size()==0)
        {
            if(deep>depth)
            {
            	depth = deep;
            	location = n;
            	return ;
			}
        }
        for(int i=0; i<pre[n].size(); i++)
        {
        	dfs(pre[n][i], deep+1);
        }
}  
int main()
{
	int n, k, d;
	cin>>n;
	door.assign(n+1, 0);
	for(int i = 0; i < n; i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>d;
			door[d]=1;
			pre[i+1].push_back(d);
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(!door[i+1])
		{
			entrance = i+1;
		}
	}
	location = entrance;
	dfs(entrance, 0);
	cout<<location<<endl;
}

