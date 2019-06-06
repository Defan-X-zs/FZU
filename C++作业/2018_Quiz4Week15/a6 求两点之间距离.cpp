//求两点之间距离
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
class Point{
private:
	double x;
	double y;
public:
	Point(double x1, double y1):x(x1),y(y1){}
	friend double Distance(Point & a, Point & b);
};
int main(){
	double ax, ay, bx, by;
	cin>>ax>>ay>>bx>>by;
	Point a(ax, ay), b(bx, by);
	printf("%.2f",Distance(a, b));
}
double Distance(Point &a, Point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}