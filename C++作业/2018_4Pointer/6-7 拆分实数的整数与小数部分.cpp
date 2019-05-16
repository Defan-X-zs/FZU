void splitfloat( float x, int *intpart, float *fracpart )//6-7 拆分实数的整数与小数部分
{
	*intpart = (int)x;
	*fracpart = x - *intpart;
}
