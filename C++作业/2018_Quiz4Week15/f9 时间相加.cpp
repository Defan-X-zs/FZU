//6-9 时间相加
void Time::DispTime(){
	cout<<hours<<"h:"<<minutes<<"m:"<<seconds<<"s";
}
Time::Time(int h, int m, int s){
	hours = h;
	minutes = m;
	seconds = s;
}
Time Time::operator + (Time & a){
	int h=0, m=0, s=0;
	s += seconds + a.seconds;
	while (s>59) {
		s-=60;
		m+=1;
	}
	m += minutes + a.minutes;
	while (m>59) {
		m-=60;
		h+=1;
	}
	h += hours + a.hours;
	Time tm(h, m, s);
	return tm;
}