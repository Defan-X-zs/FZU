//7-3 期刊收费
#include<iostream>
using namespace std;
class Periodical {
protected:
	string title; //名称
public:
	Periodical(string title):title(title){}
	virtual void display()=0;//打印收费
};
class Magazine:public Periodical
{
public:
	float price;
	int qi;
	Magazine(string title,float price,int qi):Periodical(title),price(price),qi(qi){}
	void display()
	{
		cout<<title;
		printf(" %.1f\n",price*qi);
	}
};
class Newspaper:public Periodical
{
public:
	float price;
	int week;
    int weektime;
	Newspaper(string title,float price,int week,int weektime):Periodical(title),price(price),week(week),weektime(weektime){}
	void display()
	{
		cout<<title;
		printf(" %.1f\n",price*week*weektime);
	}
};
int main()
{
	Periodical* pp[10];int n = 0;
	int type;
	string title;float price;int qi;int week;int weektime;
	cin>>type;
	while (type)
	{
		if(type==1){cin>>title>>price>>qi;pp[n++]=new Magazine(title,price,qi);}
		else if(type==2){cin>>title>>price>>week>>weektime;pp[n++]=new Newspaper(title,price,week,weektime);}
		cin>>type;
	}
	for (int i = 0; i < n; ++i)
	{
		pp[i]->display();
	}
}
