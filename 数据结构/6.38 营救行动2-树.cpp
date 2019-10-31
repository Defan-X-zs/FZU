#include<iostream>//6.38 营救行动2
using namespace std;
int main()
{
	int n, m;
	cin>>n>>m;
	int a[n+1];
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i < m; i++)
	{
		int l, r, x, ans = 0;
		char opt;
		cin>>opt;
		if(opt == 'Q')
		{
			cin>>l>>r;
			for(int j = l; j <= r; j++)
			{
				ans += a[j];
			}
			cout<<ans<<endl;
		}
		if(opt == 'C')
		{
			cin>>l>>r>>x;
			for(int j = l; j <= r; j++)
			{
				a[j] += x;
			}
		}
	}
}