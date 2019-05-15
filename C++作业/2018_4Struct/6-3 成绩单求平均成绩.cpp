double average ( Score a[], int n )//6-3 成绩单求平均成绩（结构体）
{
	double sum = 0, num = n;
	while(n--) {
		sum += a[n].score;
	}
	return sum /  num;
}
