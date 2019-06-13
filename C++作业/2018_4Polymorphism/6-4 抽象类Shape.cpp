//6-4 抽象类Shape
class Rectangle:public Shape{
protected:
	double w, h;
public:
	Rectangle(double w, double h):w(w),h(h){}
	double getArea(){
		return w*h;
	}
	double getPerim(){
		return 2*w+2*h;
	}
};
class Circle:public Shape{
protected:
	double r;
public:
	Circle(double r):r(r){}
	double getArea(){
		return PI*r*r;
	}
	double getPerim(){
		return 2*PI*r;
	}
};