#include <iostream>//7-7 求n以内最大的k个素数以及它们的和
#include <math.h>
using namespace std;
int main()
{	
	int n, k, f, sum = 0;
	cin>>n>>k;
	int s[k], a = 0 , num = n; 
	for(int j = 1; j <= n; j++) {
		f = 0;
		for(int i = 2; i < num; i++) {//判断是否素数 
			if(num % i == 0) {
				f = 1;
				break;
			}
		}  
		if(!f) {//是素数 
			
			s[a] = num;
			sum += num;
			a++;
			if(a == k) break;
		}
		num--;
		if(num < 2) break;
	}
	
	for(int i = 1; i < a; i++) {
		cout<<s[i-1]<<"+";
	}
	cout<<s[a-1]<<"="<<sum<<endl;
}
