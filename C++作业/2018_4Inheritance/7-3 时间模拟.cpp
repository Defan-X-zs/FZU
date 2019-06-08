//7-3 时间模拟
#include <iostream>
using namespace std;
class Time{
public:
	int second;
	int minute;
	int hour;
	int sum;
public:
	Time(int h, int m, int s):hour(h),minute(m),second(s){}
	void operator++(){
		sum = hour * 3600 + minute * 60 + second;
		sum++;
		second = sum % 60;
		minute = sum / 60 % 60;
		hour = sum / 3600 % 24;
	}
	void operator--(){
		sum = hour * 3600 + minute * 60 + second;
		if (sum == 0) sum = 86400;
		sum--;
		second = sum % 60;
		minute = sum / 60 % 60;
		hour = sum / 3600 % 24;
	}
};
class Time_12hours:public Time{
protected:
	string type;
public:
	string interval;
	Time_12hours(int t,int h, int m, int s):Time(h, m, s){
		if(t == 121) interval = "AM";
		else interval = "PM";
	}
	void operator --(){Time::operator --();};
    void operator ++(){Time::operator ++();};
};
class Time_24hours:public Time{
protected:
	string type;
public:
	Time_24hours(int h, int m, int s):Time(h, m, s){}
	void operator ++(){Time::operator ++();};
    void operator --(){Time::operator --();};
};
int main(){
	int t;
	char tt;
	int h, m, s, ttt;
	cin>>t;
	while (t){
		switch(t){
			case 121:
			case 122:{cin>>h>>m>>s>>tt>>ttt;Time_12hours a(t, h, m, s);
							while (ttt--) {
								if (tt == '+') ++a;
								else --a;
							}
							if(a.hour > 11) {
								a.hour -= 12;
								if(a.interval == "AM") a.interval = "PM";
								else a.interval = "AM";
							}
							cout<<a.interval<<" ";if(a.hour<10)cout<<"0";cout<<a.hour<<":";if(a.minute<10)cout<<"0";cout<<a.minute<<":";if(a.hour<10)cout<<"0";cout<<a.second<<endl; break;}
			case 24:{cin>>h>>m>>s>>tt>>ttt;Time_24hours a(h, m, s);
							while (ttt--) {
								if (tt == '+') ++a;
								else --a;
							}
							if(a.hour<10)cout<<"0";cout<<a.hour<<":";if(a.minute<10)cout<<"0";cout<<a.minute<<":";if(a.second<10)cout<<"0";cout<<a.second<<endl; break;}
		}
		cin>>t;
	}
}