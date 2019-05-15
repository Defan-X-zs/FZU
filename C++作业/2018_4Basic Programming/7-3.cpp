#include <iostream>//7-3 统计学生平均成绩与及格人数
#include <iomanip>
using namespace std;
int main()
{
	int n, m, count = 0;
	double a, scoresum = 0;
	cin>>n; m = n;
	while(n) {
			cin>>a;
			scoresum += a;
			if(a >= 60) count ++;
			n--;
		}
		if(scoresum) scoresum /= m;
		cout<<"average = "<<fixed<<setprecision(1)<<scoresum<<endl;
		cout<<"count = "<<count<<endl;
}
