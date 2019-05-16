char fun(char *c)//6-3 大写字母转换成小写字母
{
	if(*c>64 && *c<91) *c += 32;
	return *c;  
} 
