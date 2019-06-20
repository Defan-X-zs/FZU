//7-4 汽车收费
#include <iostream>
using namespace std;
class Vehicle
{ 
protected:
    string NO;//编号
public:
    Vehicle(string NO):NO(NO){}
    virtual void display()=0;//输出应收费用
};
class Car:public Vehicle
{
    public:
    int people;
    int weight;
    Car(string NO,int people,int weight):Vehicle(NO),people(people),weight(weight){}
    void display()
    {
        cout<<NO<<" "<<people*8+weight*2<<endl;
    }
};
class Truck:public Vehicle
{
    public:
    int weight;
    Truck(string NO,int weight):Vehicle(NO),weight(weight){}
    void display()
    {
        cout<<NO<<" "<<weight*5<<endl;
    }
};
class Bus:public Vehicle
{
    public:
    int people;
    Bus(string NO,int people):Vehicle(NO),people(people){}
    void display()
    {
        cout<<NO<<" "<<people*3<<endl;
    }
};
int main()
{
    int n = 0;Vehicle *pv[10];
    string NO;int weight;int people;
    int type;
    cin>>type;
    while(type)
    {
        if(type==1){cin>>NO>>people>>weight;pv[n++]=new Car(NO,people,weight);}
        if(type==2){cin>>NO>>weight;pv[n++]=new Truck(NO,weight);}
        if(type==3){cin>>NO>>people;pv[n++]=new Bus(NO,people);}
        cin>>type;
    }
    for(int i =  0;i<n;i++)
    {
        pv[i]->display();
    }
}
