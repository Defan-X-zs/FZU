//二维向量相加（C++ 运算符重载）
TDVector(double a, double b):x(a),y(b){}
double getX(){
	return x;
}
double getY(){
	return y;
}
void setX(double a){
	x = a;
}
void setY(double a){
	y = a;
}
TDVector operator + (TDVector &a){
	return TDVector(a.x+x, a.y+y);
}
