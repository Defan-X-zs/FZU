//输出较大或较小值（函数模板）
template<class T>
T m(T t, int task){
	T x1, y1;
	cin>>x1>>y1;
	switch(task){
		case 1:return (x1<y1)?y1:x1;break;
		case 2:return (x1<y1)?x1:y1;break;
	}
}