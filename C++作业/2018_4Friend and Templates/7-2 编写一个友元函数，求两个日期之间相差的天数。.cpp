//7-2 编写一个友元函数，求两个日期之间相差的天数。
#include<iostream>
using namespace std;

int sum;
int i;
int leap(int year);

class Date {
	private:
		int year,month,day;
	public:
		void set(int y,int m,int d) {
			year = y;
			month = m;
			day = d;
		}
		friend int count_day(Date d,int flag);
		friend int leap(int y);
		friend int subs(Date rect,Date rect1);
};

int count_day(Date d,int flag) {
	int day_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int day_nleap[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(leap(d.year)) {
		if( flag ) {
			sum = d.day;
			for( i=0; i<d.month-1; i++ ) {
				sum = sum + day_leap[i];
			}
		} else {
			sum = day_leap[d.month-1] - d.day;
			for( i=d.month; i<12; i++ ) {
				sum = sum + day_leap[i];
			}
		}
	} else {
		if( flag ) {
			sum = d.day;
			for( i=0; i<d.month-1; i++ ) {
				sum = sum + day_leap[i];
			}
		} else {
			sum = day_nleap[d.month-1] - d.day;
			for( i=d.month; i<12; i++ ) {
				sum = sum + day_nleap[i];
			}
		}
	}
	return sum;
}

int leap(int y) {
	int x;
	if( (y%4 ==0 && y%100!=0) || (y%100==0 && y%400==0) ) {
		//cout<<y<<" Is Leap Year"<<endl;//Test
		x = 1;
	} else {
		//cout<<y<<" Is Not Leap Year"<<endl;//Test
		x = 0;
	}
	return x;
}

int subs(Date rect,Date rect1) {
	int y,days;
	if( rect.year!=rect1.year ) {
		days = count_day(rect,0);
		for( y=rect.year+1; y<=rect1.year; y++ ) {
			if(leap(y)) {
				days = days + 366;
			} else {
				days = days + 365;
			}
		}
		days = days - count_day(rect1,0);
	} else if( rect.year==rect1.year && rect.month!=rect1.month ) {
		days = count_day(rect,0) - count_day(rect1,0);
	} else if( rect.year==rect1.year && rect.month==rect1.month && rect.day!=rect1.day) {
		days = rect1.day - rect.day;
	}
	return days;
}

int main(int argc,char *argv[]) {
	int y,m,d,y1,m1,d1;
	int flag = 1;
	Date rect,rect1;
	cin>>y>>m>>d;
	cin>>y1>>m1>>d1;
	if((y>y1)||(m>m1)||(d>d1)||(y<0)||(y1<0)||(m<=0)||(m1<=0)||(d<=0)||(d1<=0)||(m>12)||(m1>12)||(d>31)||(d1>31)) {
		flag = 0;
	}
	
	if( flag == 0 ) {
		cout<<"time error!"<<endl;
	} else {
		rect.set(y,m,d),rect1.set(y1,m1,d1);
		sum = subs(rect,rect1);
		cout<<sum<<endl;
	}
	return 0;
}
