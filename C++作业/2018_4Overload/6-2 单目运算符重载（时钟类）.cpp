//6-2 单目运算符重载（时钟类） 
//Clock operator++(Clock& op);         //前置单目运算符重载
//Clock operator++(Clock& op,int);     //后置单目运算符重载
Clock operator++(Clock& op) {
	if(++op.Second==60) {
		op.Second -= 60;
		++op.Minute;
	}
	if(op.Minute==60) {
		op.Minute -= 60;
		++op.Hour;
	} 
	if(op.Hour==24) {
		op.Hour -= 24;
	}
	return op;
}
Clock operator++(Clock& op, int) {
	Clock temp(op);
	op.Second++;
	if(op.Second==60) {
		op.Second -= 60;
		++op.Minute;
	}
	if(op.Minute==60) {
		op.Minute -= 60;
		++op.Hour;
	}
	if(op.Hour==24) {
		op.Hour -= 24;
	}
	return temp;
}
