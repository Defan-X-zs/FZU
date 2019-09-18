#include <iostream>//week2-2 最长连续递增子序列
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];		
	}
	if(n==1){cout<<a[0];return 0;}	
	int l=0,r=1,maxlen=-1,maxl,temp;
	
	while(r<n)
	{
		while((a[r-1]<a[r])&&(r<n))
		{
			r++;
		}
		temp = r-l;
		if(temp>maxlen){maxlen=temp;maxl=l;}
		l=r;
		r=l+1;
	}
	for(int i = 0; i < maxlen-1; i++)
	{
		cout<<a[maxl+i]<<" ";		
	}
	cout<<a[maxl+maxlen-1];
}
