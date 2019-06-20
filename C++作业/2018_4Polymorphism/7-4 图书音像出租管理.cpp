//7-4 图书音像出租管理
#include<iostream>
using namespace std;
class Publication
{
protected:
	string title;//名称
	float price;//原价
	int day;//租期
public:
	Publication(){}
	Publication(string title, float price, int day):title(title),price(price),day(day){}
	virtual void display()=0;//打印价格清单
};
class Book:public Publication
{
protected:
	float old;
public:
	Book(string title, float price, int day, float old):Publication(title,price,day),old(old){}
	void display()
	{
		cout<<title;
		printf(" %.1f",1.2*day);
		if(1.2*day>2*old*price)printf(" %.1f R\n",2*old*price);
		else cout<<endl;
	}
};
class Tape:public Publication
{
protected:
	int time;
public:
	Tape(string title, float price, int day, int time):Publication(title,price,day),time(time){}
	void display()
	{
		cout<<title;
		printf(" %.1f",1.2*day);
		if(1.2*day>2*price/(time/3.0+1))printf(" %.1f R\n",2*price/(time/3.0+1));
		else cout<<endl;
	}
};
int main()
{
	Publication* pp[10];
	int n = 0;
	int f;
	string t;float p;int d;float o;int time;
	cin>>f;
	while(f)
	{
		if(f==1){cin>>t>>p>>d>>o;pp[n++]=new Book(t,p,d,o);}
		else if(f==2){cin>>t>>p>>d>>time;pp[n++]=new Tape(t,p,d,time);}
		cin>>f;
	}
	for(int i = 0; i < n; i++)
	{
		pp[i]->display();
	}
}