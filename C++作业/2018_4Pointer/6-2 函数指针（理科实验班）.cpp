bool s2(const Student &a, const Student &b) {//6-2 函数指针（理科实验班）
	if(a.score[0]+a.score[1] > b.score[0]+b.score[1]) 
	return true;
	else return false;
}
bool s4(const Student &a, const Student &b) {
	if(a.score[0]+a.score[1]+a.score[2]+a.score[3] > b.score[0]+b.score[1]+b.score[2]+b.score[3]) 
	return true;
	else return false;
}
int select(Student *st, int n, bool (*s)(const Student &, const Student &))
{
	int maxn = 0;
	for(int i = 1; i < n; i++) {
		if(s(st[maxn], st[i])) continue;
		else maxn = i;
	} 
	return st[maxn].num;
}
