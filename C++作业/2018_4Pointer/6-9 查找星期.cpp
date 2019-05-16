int getindex( char *s )//6-9 查找星期
{
	int i;
	char week[7][10] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	for (i = 0; i <= 6; i++)
	{
		if (!strcmp(s, week[i])) break;
	}
	if (i == 7) i = -1;
	return i;
}
