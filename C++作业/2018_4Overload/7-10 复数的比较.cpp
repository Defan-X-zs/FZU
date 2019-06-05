//7-10 复数的比较
#include <iostream>
using namespace std;
class fs{
	private:
		int real;
		int imag;
	public:
		fs(){}
		fs(int r, int i):real(r),imag(i){}
		friend bool operator > (fs &f1, fs &f2);
};
int main(){
	int r1, i1, r2, i2;
	while(cin>>r1>>i1>>r2>>i2){
		if(r1==0&&i1==0&&r2==0&&i2==0) break;
		fs f1(r1, i1), f2(r2, i2);
		if(f1>f2)cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}
}
bool operator > (fs &f1, fs &f2){
	if(f1.real*f1.real+f1.imag*f1.imag > f2.real*f2.real+f2.imag*f2.imag) {
		return true;
	}
	else return false;
}
