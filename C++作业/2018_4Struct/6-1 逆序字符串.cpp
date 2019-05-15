void reverse_string (string &str) //6-1 逆序字符串	
{
	int len = 0, i = 0, temp;
	while(str[len]!='\0') len++;
	while(i<len/2) {
		temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1]= temp; 
		i++;
	}
}
