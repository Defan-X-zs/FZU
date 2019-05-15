#include <iostream>//7-9 求给定数num的所有真因子之积
using namespace std;
int main()
{	
	int n, sum = 1;
	cin>>n;
	for(int i = 1; i < n; i++) {
		if(n % i == 0) {
			sum *= i;
		}
	}
	cout<<sum<<endl;
}
