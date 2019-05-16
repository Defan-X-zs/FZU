int max(int a, int b)//6-1 函数调用
{
	return a>b?a:b;
}
int min(int a, int b)
{
	return a>b?b:a;
}
int sum(int a, int b)
{
	return a+b;
}
int compute(int a, int b, int(*func)(int , int ))
{
	int res = func(a, b);
	return res;
}
