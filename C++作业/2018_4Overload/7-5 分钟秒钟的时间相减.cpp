//77-5 分钟秒钟的时间相减
#include<iostream>
#include<stdlib.h>
using namespace std;
class Time
{
      int m;
      int s;
      public:
             void set(int m,int s){this->m=m;this->s=s;}
             int operator -(Time&);
};
int Time::operator -(Time& p)
{
    int s1,s2;
    s1=m*60+s;
    s2=p.m*60+p.s;
    return s1-s2>0?s1-s2:s2-s1;
}
int main()
{
    Time t1,t2;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    while(a!=0||b!=0||c!=0||d!=0)
    {
      t1.set(a,b);
      t2.set(c,d);
      cout<<t1-t2<<endl;
      cin>>a>>b>>c>>d;
    }
    return 0;
}