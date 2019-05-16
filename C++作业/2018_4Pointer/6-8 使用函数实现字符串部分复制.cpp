void strmcpy( char *t, int m, char *s )//6-8 使用函数实现字符串部分复制
{
	if(m>20) *s = ' ';
	else 
	{
		t+=m-1;
		while(*t) {
			*s++ = *t++;
		}
	}
}
