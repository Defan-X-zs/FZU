//7-3 时间换算
#include<iostream>
using namespace std;
class Time
{
    private:
        long long hour,minute,second;    
    public:
        friend Time operator+(Time &now,long long n);
        void display();
        Time(long long h,long long m,long long s);
        Time();  
};
Time::Time(long long h,long long m,long long s)
{
    hour = h;
    minute = m;
    second = s;
}
void Time::display()
{
    cout<<"time:"<<hour<<":"<<minute<<":"<<second<<endl;
}
Time operator+(Time &now,long long n)
{
    now.second += n;
    if(now.second>=60)
    {
        now.minute += now.second / 60;
        now.second = now.second % 60;    
    }
    else if(now.second<0)        //坑点 会出现负数的情况
    {
        now.minute -= (-now.second)/60 +1;
        now.second += ((-now.second)/60 +1) * 60;
        
    }
    if(now.minute>=60)
    {
        now.hour += now.minute / 60;
        now.minute = now.minute % 60;    
    }
    else if(now.minute<0)        
    {
        now.hour-= (-now.minute)/60 +1;
        now.minute += ((-now.minute)/60 +1) * 60;
    }
    if(now.hour>=24)            now.hour = now.hour % 24;
    else if(now.hour<0)            now.hour += ((-now.hour)/24 +1 ) * 24;
    return now;
    
}
int main()
{
    long long h,m,s,n;
    cin>>h>>m>>s>>n;
    while(h!=0||s!=0||n!=0||m!=0)
    {
        Time now(h,m,s);
        Time he = now + n;
        he.display();
        cin>>h>>m>>s>>n;
    }
    return 0;
}