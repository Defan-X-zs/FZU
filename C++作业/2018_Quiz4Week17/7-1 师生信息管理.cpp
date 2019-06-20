//7-1 师生信息管理
#include <iostream>
using namespace std;
class Person
{
protected:
int NO;//编号
public:
Person(int NO):NO(NO){}
virtual void display()=0;//输出相关信息
};
class Student:public Person
{
    public:
    int sum=0,num=0;
    int q[5];
    Student(int NO,int a[]):Person(NO){q[0]=a[0],q[1]=a[1],q[2]=a[2],q[3]=a[3],q[4]=a[4];}
    void display()
    {
        cout<<NO;
        for(int i=0;i<5;i++)
        {
            if(q[i]==-1) num++;
            else sum+=q[i];  
        }
        cout<<" "<<num;
        if(num!=5)printf(" %.1f",sum*1.0/(5.0-num)*1.0);
        cout<<endl;
    }
};
class Teacher:public Person
{
    public:
    int paper[3];
    Teacher(int NO,int p[]):Person(NO){paper[0]=p[0],paper[1]=p[1],paper[2]=p[2];}
    void display()
    {
        cout<<NO<<" "<<paper[0]+paper[1]+paper[2]<<endl;
    }
};
int main()
{
    int n=0;
    Person *pp[10];int NO;int a[5];int p[3];
    int type;
    cin>>type;
    while(type)
    {
        if(type==1){cin>>NO>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];pp[n++]=new Student(NO,a);}
        else if(type==2){cin>>NO>>p[0]>>p[1]>>p[2];pp[n++]=new Teacher(NO,p);}
        cin>>type;
    }
    for(int i=0;i<n;i++)
    {
        pp[i]->display();
    }
}
