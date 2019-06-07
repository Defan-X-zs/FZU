//7-2 日程安排（多重继承+重载）
#include <iostream>
using namespace std;
class Date{
protected:
 	int year;
 	int month;
 	int day;
public:
  	Date(int y,int mon,int d):year(y),month(mon),day(d){}
  	void showdate(){
  		cout<<" "<<year<<"/"<<month<<"/"<<day;
  	}
};
class Time{
protected:
 	int hour;
 	int minute;
 	int second;
public:
  	Time(int h,int min,int s):hour(h),minute(min),second(s){}
  	void showtime(){
  		cout<<" "<<hour<<":"<<minute<<":"<<second;
  	}
};
class Schedule:public Date,public Time{
 	int ID;
public:
  	bool operator < (const Schedule & s2);
  	Schedule(int id,int y,int mon,int d,int h,int min,int s):Date(y,mon,d),Time(h,min,s),ID(id){}
  	void show();
};
bool Schedule::operator < (const Schedule & s2){
 	if(year<s2.year)
 		return 1;
 	else if(year>s2.year)
 		return 0;
 	else{
  		if(month<s2.month)
  			return 1;
  		else if(month>s2.month)
  			return 0;
  		else{
   			if(day<s2.day)
   				return 1;
   			else if(day>s2.day)
   				return 0;
   			else {
    			if(hour<s2.hour)
    				return 1;
    			else if(hour>s2.hour)
    				return 0;
    			else{
     				if(minute<s2.minute)
     					return 1;
     				else if(minute>s2.minute)
     					return 0;
     				else {
      					if(second<s2.second)
      						return 1;
      					else 
      						return 0;
     				}
   				}
   			}
  		}
 	}
}
void Schedule::show(){
	cout<<"No."<<ID<<":";
	Date::showdate();
	Time::showtime();
}
int main()
{
	int id,y,mon,d,h,min,s,i=0;
	Schedule s2(0,9999,9999,9999,999,999,99);
	while(1)
	{
		cin>>id;
		if(id==0)
		break;
		i++; 
		scanf("%d/%d/%d",&y,&mon,&d);
		scanf("%d:%d:%d",&h,&min,&s);
		Schedule s1(id,y,mon,d,h,min,s);
		if(s1<s2) s2=s1;
	}
	if(i!=0)
	{
		cout<<"The urgent schedule is ";s2.show();
	}
	return 0;
}
