//6-1 使用类计算矩形的面积
void Rectangle::setLength(int l){
	length = l;
}
void Rectangle::setWidth(int w){
	width = w;
} 
int Rectangle::getArea(){
	return length * width;
}
