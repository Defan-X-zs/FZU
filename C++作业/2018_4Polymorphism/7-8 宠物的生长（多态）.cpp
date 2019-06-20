//7-8 宠物的生长（多态）
#include<iostream>
using namespace std;
class Pet
{
protected:
	string name;//姓名
	int length;//身长
	int weight;//体重
	int current;//当前日
public:
	virtual void display(int day)=0;//输出目标日期的身长和体重
	Pet(string name, int l, int w, int c):name(name),length(l),weight(w),current(c){}
};
class Cat:public Pet
{
public:
	Cat(string name,int l,int w,int c):Pet(name,l,w,c){}
	void display(int day)
	{
		length+=(day-current);
		weight+=2*(day-current);
		cout<<name<<" "<<length<<" "<<weight<<endl;
	}
};
class Dog:public Pet
{
public:
	Dog(string name,int l,int w,int c):Pet(name,l,w,c){}
	void display(int day)
	{
		length+=2*(day-current);
		weight+=(day-current);
		cout<<name<<" "<<length<<" "<<weight<<endl;
	}
};
int main()
{
	int n = 0;
	int f;
	Pet* pt[10];
	string name;int length;int weight;int day;int current;
	cin>>f;
	while(f)
	{
		if(f==1){cin>>name>>length>>weight>>current;pt[n++]=new Cat(name,length,weight,current);cin>>f;}
		else if(f==2){cin>>name>>length>>weight>>current;pt[n++]=new Dog(name,length,weight,current);cin>>f;}
		else {day = f;break;}
	}
	for (int i = 0; i < n; ++i)
	{
		pt[i]->display(day);
	}
}
