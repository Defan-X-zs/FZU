//7-9 运算符重载
#include <iostream>
using namespace std;
class fs{
	private:
		int fz;
		int fm;
	public:
		fs(){}
		fs(int z, int m):fz(z),fm(m){}
		void display(){
			if(fz%fm == 0) {
				cout<<fz/fm;
			}
			else {
				cout<<fz<<" "<<fm;
			}
		}
		friend fs operator + (fs &f1, fs &f2);
};
int main(){
	int fz, fm;
	cin>>fz>>fm;
	fs f1(fz, fm);
	cin>>fz>>fm;
	fs f2(fz, fm);
	fs f3 = f1 + f2;
	f3.display();
}
int measure(int x, int y){
	int z = y;
	while (x%y!=0) {
		z = x%y;//辗转相除法
		x = y;
		y = z;
	}
	return z;
}
fs operator + (fs &f1, fs &f2){
		int y = f1.fm*f2.fm;
		int x = (f1.fz*f2.fm)+(f2.fz*f1.fm);
		int a = measure(x, y);
		x = x / a;
		y = y / a;
		if (y<0)
		{
			x = -x;
			y = -y;
		}
		return fs(x, y);
}
