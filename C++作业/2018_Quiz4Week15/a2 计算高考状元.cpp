//计算高考状元
#include <iostream>
using namespace std;
class student{
private:
	int chinese;
	int math;
	int english;
	int com;
public:
	int sum() {return chinese+math+english+com;}
	void set(int a, int b, int c, int d){chinese=a,math=b,english=c,com=d;}
	friend student top(const student *p, int count);
};
int main(){
	student stu[100];
	string n;
	int a, b, c, d, i=0, max=0;
	cin>>n;
	while(n!="0"){
		cin>>a>>b>>c>>d;
		stu[i].set(a, b, c, d);
		if(max<stu[i].sum()) max = stu[i].sum();
		i++;cin>>n;
	}
	cout<<max;
}