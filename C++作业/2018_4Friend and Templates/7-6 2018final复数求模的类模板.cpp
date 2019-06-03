//7-6 2018final复数求模的类模板
#include <iostream>
#include <math.h>
using namespace std;
template <class numtype>
class complex{
	private:
		numtype real, imag;
	public:
		complex (numtype r, numtype i){
			real = r;
			imag = i;
		}
		numtype mod();
};
template <class numtype>
numtype complex <numtype>::mod(){
	return sqrt(real*real + imag*imag);
} 
int main(){
	int f, r, i;
	cin>>f;
	if (f==1) {
		int r, i;
		cin>>r>>i;
		complex <int> com1(r, i);
		cout<<com1.mod();
	}
	else if (f==2) {
		float r, i;
		cin>>r>>i;
		complex <float> com1(r, i);
		cout<<com1.mod();
	}
	else if (f==3) {
		double r, i;
		cin>>r>>i;
		complex <double> com1(r, i);
		cout<<com1.mod();
	} 
	
}
