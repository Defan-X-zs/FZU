//绪论1.1 fibonacci
#include<iostream>
using namespace std;
int main()
{
	int N, A, B;
	cin>>N>>A>>B;
	
 	int res[N], num, p = 1, q = 1, temp;
	for(int i = 0; i < N; i++) 
	{
		cin>>num;
		for(int j = 0; j < num-1; j++)
		{
			temp = q;
			q = A * q + B * p;
			q%=2013;
			p = temp;
		}
		res[i] = q;
		p = 1; q = 1;
	}
	
	for(int i = 0; i < N; i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}
