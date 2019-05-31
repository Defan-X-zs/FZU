//6-4 面积计算器（函数重载）
int area(int x, int y){
	return x * y;
}
int area(int x, int y, int z){
	return 2 * (x * y + x * z + y * z);
}
