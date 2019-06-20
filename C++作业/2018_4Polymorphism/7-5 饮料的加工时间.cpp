//7-5 饮料的加工时间
#include<iostream>
using namespace std;
class Drink
{
protected:
	int NO; //编号
	int amount; //数量
public:
	Drink(int NO, int amount):NO(NO),amount(amount){}
	virtual void display()=0;//输出提供时间
};
class Tea:public Drink
{
public:
	int t;
	Tea(int NO, int amount,int t):Drink(NO,amount),t(t){}
	void display()
	{
		if(t==1) cout<<NO<<" "<<50*amount<<endl;
		else cout<<NO<<" "<<20*amount<<endl;
	}
};
class Coffee:public Drink
{
public:
	int t;
	Coffee(int NO, int amount,int t):Drink(NO,amount),t(t){}
	void display()
	{
		if(t==1) cout<<NO<<" "<<120*amount<<endl;
		else cout<<NO<<" "<<20*amount<<endl;
	}
};
class Milk:public Drink
{
public:
	int t;
	Milk(int NO, int amount,int t):Drink(NO,amount),t(t){}
	void display()
	{
		cout<<NO<<" "<<10*amount<<endl;
	}
};
int main()
{
	int type;
	Drink* d[10];
	int NO;int amount;int t;int n=0;
	cin>>type;
	while(type)
	{
		if(type==1){cin>>NO>>amount>>t;d[n++]=new Tea(NO,amount,t);}
		if(type==2){cin>>NO>>amount>>t;d[n++]=new Coffee(NO,amount,t);}
		if(type==3){cin>>NO>>amount;d[n++]=new Milk(NO,amount,0);}
		cin>>type;
	}
	for (int i = 0; i < n; ++i)
	{
		d[i]->display();
	}
}