#include<iostream>//7-1 文件传输 
using namespace std;
int u[10005];
int find(int idx)
{
    while(idx != u[idx])
    {
        u[idx] = u[u[idx]];
        idx = u[idx];
    }
    return idx;
}
void uni(int a, int b)
{
    int aRoot = find(a);
    int bRoot = find(b);
    if(aRoot != bRoot)
    {
        u[bRoot] = aRoot;
    }
}
bool isConnected(int p, int q)
{
    int pRoot = find(p);
    int qRoot = find(q);
    if(pRoot != qRoot)
    {
        return false;
    }
    return true;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)u[i]=i;
	char c;
	cin>>c;
	int a, b; 
	while(c!='S')
	{
		if(c=='I')
		{
		cin>>a>>b;
		uni(a, b);
		}
		else if(c=='C')
		{
		cin>>a>>b;
		if(isConnected(a,b))cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		}
		cin>>c;
	}
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(u[i]==i)count++;
	}
	if(count==1) cout<<"The network is connected."<<endl;
	else cout<<"There are "<<count<<" components."<<endl;
}
