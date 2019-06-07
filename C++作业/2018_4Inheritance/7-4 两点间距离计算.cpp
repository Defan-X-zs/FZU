//7-4 两点间距离计算
#include <iostream>
#include <math.h>
using namespace std;
class Point_1D
{	
protected:
	float x, x1;
public:
	Point_1D(float p, float p1):x(p),x1(p1){}
	float distance(){
		return sqrt((x-x1)*(x-x1));
	}
};
class Point_2D:public Point_1D
{
protected:
	float y, y1;
public:
	Point_2D(float p, float p1, float q, float q1):Point_1D(p, p1),y(q),y1(q1){}
	float distance(){
		return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
	}
};
class Point_3D:public Point_2D
{
protected:
	float z, z1;
public:
	Point_3D(float p, float p1, float q, float q1, float r, float r1):Point_2D(p, p1, q, q1),z(r), z1(r1){}
	float distance(){
		return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1));
	}
};
int main()
{
	int func;
	float p, p1, q, q1, r, r1;
	cin>>func;
	while (func) {
		switch(func){
			case 1:{cin>>p>>p1;Point_1D a(p, p1);cout<<"Distance from Point "<<p<<" to Point "<<p1<<" is "<<a.distance()<<endl;break;}
			case 2:{cin>>p>>q>>p1>>q1;Point_2D b(p, p1, q, q1);cout<<"Distance from Point("<<p<<","<<q<<") to Point("<<p1<<","<<q1<<") is "<<b.distance()<<endl;break;}
			case 3:{cin>>p>>q>>r>>p1>>q1>>r1;Point_3D c(p, p1, q, q1, r, r1);cout<<"Distance from Point("<<p<<","<<q<<","<<r<<") to Point("<<p1<<","<<q1<<","<<r1<<") is "<<c.distance()<<endl;break;}
		}
		cin>>func;
	}
}