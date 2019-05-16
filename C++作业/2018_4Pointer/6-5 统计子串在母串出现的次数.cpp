int fun(char *str,char *substr)//6-5 统计子串在母串出现的次数
{
	int n=0;
	while(*(str+2) != '\0') {
		if(*str == *substr && *(str+1) == *(substr+1) && *(str+2) == *(substr+2))
			n++;
		*str++;
	}	
	return n;
}
