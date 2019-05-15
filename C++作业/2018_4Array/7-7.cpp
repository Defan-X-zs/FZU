#include <iostream>//7-7 求二维数组周边元素的累加和
using namespace std;
int main()
{
	int a[20], sum=0;
	for (int i = 0; i<20; i++) cin>>a[i];
	sum = a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[9]+a[10]+a[14]+a[15]+a[16]+a[17]+a[18]+a[19];	
	cout<<sum<<endl;
	return 0;
}
