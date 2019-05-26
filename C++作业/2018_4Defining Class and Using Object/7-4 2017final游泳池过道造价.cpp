//7-4 2017final游泳池过道造价
#include<iostream>
#define PI 3.14159
using namespace std;
class Circle{
	public:
		void setr(double r) {
			radius = r;
		}
		double s() {
			return PI*radius*radius;
		}
	private:
		double radius;
};

class Rectangle{
	public:
		void setl(double l) {
			length = l;
		}
		void setw(double w) {
			width = w;
		}
		double s() {
			return length * width;
		}
		double length, width;
};

int main() {
	Rectangle y;
	Circle x;
	double a, b, c, res;
	cin>>a>>b>>c;
	x.setr(a);
	y.setl(b);
	y.setw(c);
	res = 20 * (y.s() - x.s());
	cout<<res;
}
