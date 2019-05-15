#include <iostream>
using namespace std;
int main()
{	
	int repeat, n, t, i, a[]={0,0,0,0,0};
	cin>>repeat;
	while(repeat--) {
		a[0]=0, a[1]=0, a[2]=0, a[3]=0, a[4]=0;
		cin>>n;
		while(n--) {
			cin>>t;
			if(t == 1) a[0]++;
			else if(t == 2) a[1]++;
			else if(t == 3) a[2]++;
			else if(t == 4) a[3]++;
			else a[4]++;
		}
		i = 5;
		while(i--) {
			cout<<5-i;
			cout<<":";
			while(a[4-i]--) {
				cout<<"*";
			}
			cout<<endl;			
		}
	}
}
