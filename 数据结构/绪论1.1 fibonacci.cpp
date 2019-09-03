//绪论1.1 fibonacci
#include<iostream>
using namespace std;
int main()
{
	int N, A, B;
	cin>>N>>A>>B;
	
 	int num[N], nummax = 0; 
	for(int i = 0; i < N; i++) 
	{
		cin>>num[i];
		if (num[i]>nummax);
		nummax = num[i];
	}
	
	int res[nummax];res[0] = 1;res[1] = 1;
	for(int i = 2; i <= nummax; i++) 
	{
		res[i] = (A*res[i-1]+B*res[i-2])%2013;
	}
	
	for(int i = 0; i < N; i++)
	{
		cout<<res[num[i]]<<endl;
	}
	return 0;
}
