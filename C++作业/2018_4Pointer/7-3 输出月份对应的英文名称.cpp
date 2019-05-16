#include <iostream> //7-3 输出月份对应的英文名称
#include <string>

using namespace std;
 
int main()
{
	int repeat;
	int i;
	cin>>repeat;
	string month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	while(repeat--) {
		cin>>i;
		if (i < 1 || i > 12) {
			cout<<"Wrong input!"<<endl;
		}
		else {
			cout<<month[i-1]<<endl;
		}	
	}
}

