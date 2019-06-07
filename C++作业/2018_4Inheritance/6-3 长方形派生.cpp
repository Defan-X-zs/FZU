//6-3 长方形派生
class Box:public Rectangle
{
public:
	Box(int l, int w, int h):Rectangle(l, w),height(h){}
	double volume(){
		return area()*height;
	}
private:
	double height;
};