void fun(int *p,int *q)//6-4 两个4位正整数的后两位互换
{
	int temp;
	temp = (*p/100)*100+*q%100;
	*q = (*q/100)*100+*p%100;
	*p = temp;
}
