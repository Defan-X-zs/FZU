char* StrStr(const char *txt, const char *pat)//6-3 字符串 - 6. 查找子串(BF算法)* err
{
	char *ret = NULL;
	char *p,*q,*txtFirst;
	int flag = 0;
	while( *txt != '\0') {
		p = txt;
		q = pat;
		txtFirst = txt;    //记录首地址 
		while( *q != '\0') {
			if( *p == *q ) {
				p++;
				q++;
			}
			else {
				break;
			}
		}
		if( *q == '\0') {
			flag = 1; 
			break;
		}
		txt++;
	}
	if( flag) ret = txtFirst;
	return ret;
}


