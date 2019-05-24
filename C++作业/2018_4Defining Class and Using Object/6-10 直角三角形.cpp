//6-10 直角三角形
class RTriangle {
	public:
		RTriangle(double x, double y) {
			a = x;
			b = y;
		}
		double getArea() {
			return a*b / 2;
		}
		double getPerimeter() {
			return a + b + sqrt(a*a+b*b);
		}
	private:
		double a, b;
};
