//6-2 Point类的声明和实现
class Point{
	public:
		void setX(double x1) {
			x = x1;
		} 
		void setY(double y1) {
			y = y1;
		}
		double getX() {
			return x;
		}
		double getY() {
			return y;
		}
	private:
		double x, y; 
};
