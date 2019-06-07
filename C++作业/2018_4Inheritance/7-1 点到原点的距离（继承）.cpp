//7-1 点到原点的距离（继承）
#include <iostream>
#include <math.h>
using namespace std;
class Point_1D
{	
protected:
	float x;
public:
	Point_1D(float p):x(p){}
	float distance(){
		return sqrt(x*x);
	}
};
class Point_2D:public Point_1D
{
protected:
	float y;
public:
	Point_2D(float p, float q):Point_1D(p),y(q){}
	float distance(){
		return sqrt(x*x+y*y);
	}
};
class Point_3D:public Point_2D
{
protected:
	float z;
public:
	Point_3D(float p, float q, float r):Point_2D(p, q),z(r){}
	float distance(){
		return sqrt(x*x+y*y+z*z);
	}
};
int main()
{
	int func;
	float p, q, r;
	cin>>func;
	while (func) {
		switch(func){
			case 1:{cin>>p;Point_1D a(p);cout<<"Distance from Point "<<p<<" to original point is "<<a.distance()<<endl;break;}
			case 2:{cin>>p>>q;Point_2D b(p, q);cout<<"Distance from Point("<<p<<","<<q<<") to original point is "<<b.distance()<<endl;break;}
			case 3:{cin>>p>>q>>r;Point_3D c(p, q, r);cout<<"Distance from Point("<<p<<","<<q<<","<<r<<") to original point is "<<c.distance()<<endl;break;}
		}
		cin>>func;
	}
}