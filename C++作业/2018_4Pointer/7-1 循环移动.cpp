#include <iostream>// 7-1 循环移动

using namespace std;

void mov(int* x,int n,int m)
{
	int *y = x ,temp[11] = {0};
	for(int i=0;i<n;i++)
	    temp[(i+m)%n] = y[i];
	for(int i=0;i<n;i++)
	    x[i] = temp[i];
}

int main() 
{
	int n,m;
	cin>>n>>m;
	int x[n];
	for(int i=0;i<n;i++)
	    cin>>x[i];
	mov(x,n,m);
	cout<<"After move: ";
	cout<<x[0];
	for(int i=1;i<n;i++)
	    cout<<" "<<x[i];
	return 0;
}

